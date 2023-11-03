# solidity2cpn

This repository is dedicated to our on-going work on the formal verification of
Solidity smart contracts using Coloured Petri Nets.

## Folder structure


```bash
.
├── app            # folder containing the CLI's source code of the tool
├── case_studies
│   ├── models     # folder containing the CPN models of the use cases, designed using CPN Tools
│   └── logs       # folder containing the state space analysis carried out by CPN Tools for the use cases
├── docs           # folder containing the documentation of the tool
│   └── reports    # folder containing extended versions of the published papers
├── include        # folder containing the headers of the code
├── src            # folder containing the source code of the proposed Solidity-to-CPN transformation
├── tests          # folder containing unit tests of the tool
└── third-party    # folder containing the external libraries used in the tool
```

## Build

The dependencies for this tool are:

- `cmake >= 3.12`
- `doxygen`
- `g++`
- `graphviz`

The tool can be compiled as follows:

```
mkdir build && cd build
cmake -DBUILD_DOCS=ON ..
cmake --build . --target install
```