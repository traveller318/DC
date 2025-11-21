from xmlrpc.server import SimpleXMLRPCServer
from socketserver import ThreadingMixIn

class ThreadingXMLRPCServer(ThreadingMixIn, SimpleXMLRPCServer):
    pass
 

# Remote arithmetic functions
def add(a, b):
    return a + b

def sub(a, b):
    return a - b

def mul(a, b):
    return a * b

def div(a, b):
    if b == 0:
        return "Error: Division by zero"
    return a / b

# Create RPC server
server = ThreadingXMLRPCServer(("localhost", 5000), allow_none=True)
print("Arithmetic RPC Server running on port 5000...")

# Register functions
server.register_function(add, "add")
server.register_function(sub, "sub")
server.register_function(mul, "mul")
server.register_function(div, "div")

# Run forever
server.serve_forever()
