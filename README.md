# Desktop CMS

## Building

1. Clone the repository, including submodules:

    ```bash
    git clone --recursive-submodules https://github.com/ImJimmi/hackday10-desktop-cms.git
    ```

### Build on the command-line

1. Configure CMake:

    ```bash
    cd hackday10-desktop-cms
    cmake -Bbuild -GNinja
    ```

2. Build:

    ```bash
    cmake --build build --config Release
    ```

### Build with Visual Studio Code

1. Open in VS Code:

    ```bash
    code hackday10-desktop-cms
    ```

2. Install [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)

3. Press <kbd>F5</kbd> to launch the debugger

### Python

1. Install dependencies

    ```bash
    cd hackday10-desktop-cms
    pip3 install -r app/scripts/requirements.txt
    ```
