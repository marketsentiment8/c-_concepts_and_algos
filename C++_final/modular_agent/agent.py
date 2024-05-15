import os
import random
import re
import sys
import time
import subprocess
import requests
from LLM import gpt4_api
import pcapy
import clamd

def load_plugins():
    plugins = []
    # Load Python plugin modules from plugins directory
    plugin_files = os.listdir('plugins')
    for file in plugin_files:
        if file.endswith('.py'):
            module_name = file[:-3]
            plugin_module = __import__('plugins.' + module_name, fromlist=[module_name])
            plugins.append(plugin_module)
    return plugins

class ReinforcementAgent:
    def __init__(self, av_api_url):
        self.av_api_url = av_api_url

    def send_alert(self, detection_event, trigger_info=None):
        if trigger_info is not None:
            detection_event['trigger_info'] = trigger_info

        response = requests.post(self.av_api_url + '/api/alerts', json=detection_event)
        if response.status_code == 200:
            print("Alert sent successfully.")
        else:
            print("Failed to send alert:", response.text)

    def receive_instructions(self):
        response = requests.get(self.av_api_url + '/api/instructions')
        if response.status_code == 200:
            return response.json()
        else:
            print("Failed to receive instructions:", response.text)
            return None

def detect_code(code):
    #ClamAV for file-based detection
    clamav = clamd.ClamdUnixSocket()
    result = clamav.scan_stream(code.encode())
    if 'FOUND' in result:
        return True  # Code is detected as infected
    else:
        return False

def capture_packets():
    # Capture packets using Npcap
    cap = pcapy.open_live("eth0", 65536, 1, 0)
    packet_count = 0
    while packet_count < 10:  # Capture 10 packets
        header, packet = cap.next()
        print(packet)
        packet_count += 1

def generator(n, av_api_url):
    plugins = load_plugins()
    agent = ReinforcementAgent(av_api_url)

    for _ in range(n):
        # Generate modified code using GPT-4 API
        reasoning, modified_code = gpt4_api.generate_modified_code()
        print(reasoning)

        timestamp = int(time.time())
        random_num = random.randint(10000, 99999)
        new_file = f"MAA-{random_num}-{timestamp}.py"
        print(f"Writing agent to {new_file}")
        if modified_code:
            with open(new_file, 'w') as write_file:
                write_file.write(modified_code)
            if detect_code(modified_code):
                # Additional information for trigger
                trigger_info = {"plugin": "None", "code_part": "Whole Code"}
                detection_event = {"type": "code_detection", "code": modified_code}
                agent.send_alert(detection_event, trigger_info)
                instructions = agent.receive_instructions()
                if instructions:
                    # Apply instructions
                    print("Applying instructions:", instructions)
                    # For demonstration, we're printing instructions, but you should apply them to the agent
            subprocess.Popen(["python", new_file])
            time.sleep(1)

if __name__ == "__main__":
    av_api_url = 'http://localhost:5000'  # Replace with the URL of your AV API
    generator(10, av_api_url)
