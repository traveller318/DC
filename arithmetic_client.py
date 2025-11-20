import xmlrpc.client

# Connect to the remote server
proxy = xmlrpc.client.ServerProxy("http://localhost:5000/")

print("=== Remote Arithmetic Client ===")

while True:
    print("\nChoose operation:")
    print("1. Add")
    print("2. Subtract")
    print("3. Multiply")
    print("4. Divide")
    print("5. Exit")

    choice = input("Enter choice (1–5): ")

    if choice == "5":
        print("Exiting client.")
        break

    if choice not in ["1", "2", "3", "4"]:
        print("Invalid choice. Try again.")
        continue

    # Get numbers from user
    a = float(input("Enter first number: "))
    b = float(input("Enter second number: "))

    # Perform remote call
    if choice == "1":
        result = proxy.add(a, b)
    elif choice == "2":
        result = proxy.sub(a, b)
    elif choice == "3":
        result = proxy.mul(a, b)
    elif choice == "4":
        result = proxy.div(a, b)

    print("Result:", result)
