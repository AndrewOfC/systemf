#! /usr/bin/env python3

# MIT License
#
# Copyright (c) 2023 Andrew E. Page
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.


import sys, re

def parseosrelease(path="/etc/os-release"):
    r = re.compile(r"""^([^=]+)\s*="?([^"]*)"?\s*""")
    
    return dict(map(re.Match.groups, map(r.match,
            filter((lambda l: l), # remove blank/nonmatch lines
                   map(str.strip, # strip new lines
                       open(path))))))    

def main():
    d = parseosrelease()
    
    for k in sys.argv[1:]:
        print(d[k])
if __name__ == '__main__':
    main()
