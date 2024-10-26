# Aimflow
[Fixes stuttery mouse input when using an external framerate limiter with Halo Infinite.](https://www.youtube.com/watch?v=4pJd-dKW7WY)

## Installation
- Download the latest release from [GitHub Releases](https://github.com/Aetopia/Aimflow/releases/latest).
   
- Open Halo Infinite's installation directory.
   
- Replace `DumpTool.exe` in:

    - Multiplayer: `<Installation Directory>\game`
      
    - Campaign: `<Installation Directory>\subgames\CampaignS1`

## Building
1. Install [MSYS2](https://www.msys2.org/) & [UPX](https://upx.github.io/) for optional compression.
2. Update the MSYS2 Environment until there are no pending updates using:

    ```bash
    pacman -Syu --noconfirm
    ```

3. Install GCC using:

    ```bash
    pacman -S mingw-w64-ucrt-x86_64-gcc --noconfirm
    ```

3. Make sure `<MSYS2 Installation Directory>\ucrt64\bin` is added to the Windows `PATH` environment variable.
4. Run [`Build.cmd`](src/Build.cmd).
