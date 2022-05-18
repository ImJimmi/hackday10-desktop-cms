# Desktop CMS

## Building

1. Clone the repository, including submodules:

    ```bash
    git clone --recursive-submodules https://github.com/ImJimmi/hackday10-desktop-cms.git
    ```

### Build on the command-line

2. Configure CMake:

    ```bash
    cd hackday10-desktop-cms
    cmake -Bbuild -GNinja
    ```

3. Build:

    ```bash
    cmake --build build --config Release
    ```

### Build with Visual Studio Code

2. Open in VS Code:

    ```bash
    code hackday10-desktop-cms
    ```

3. Install [C/C++ Extension Pack](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)

4. Press <kbd>F5</kbd> to launch the debugger
