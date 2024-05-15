import requests

class ReinforcementAgent:
    def __init__(self, av_api_url):
        self.av_api_url = av_api_url

    def send_alert(self, detection_event):
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
