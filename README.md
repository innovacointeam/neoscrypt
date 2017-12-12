# nesoscrypt
Neoscrypt hash in C wrapped in python module

It can be installed or built with python 2 or 3. Just use the right python version to install or build.

# Install
python 2: python setup.py install <br/>
python 3: python3 setup.py install<br/>

# Build
python 2: python setup.py build<br/>
python 3: python3 setup.py build


# Using the module
import neoscrypt<br/>

In python 2 input data should be in string: <br/>
data = '00'.decode('hex') <br/>

In python 3 input data must be in bytes: <br/>
data = b'\x00'<br/>

hashed = neoscrypt.getPoWHash(data)<br/>
