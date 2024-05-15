# plugins/plugin1.py

def execute():
    # Perform a complex task
    result = perform_complex_task()
    
    # Check the result and return a string indicating the execution result
    if result:
        return "The complex task was successfully executed."
    else:
        return "Failed to execute the complex task."

def perform_complex_task():
    # Simulate a complex task
    try:
        # Perform some computations or operations
        result = 1 + 2 * 3 - 4 / 2
        
        # Return True if the task was successful
        return True
    except Exception as e:
        # Print the error message if an exception occurs
        print(f"Error performing complex task: {e}")
        return False
