# SFML base code
## How to setup
### Windows
Install [chocolatey](https://chocolatey.org/install)\
`choco install llvm`\
`choco install mingw`
### MacOS
`(/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install.sh)")`\
`brew install --with-toolchain llvm`\
`brew install gdb`
### Linux
**If your distro is not listed then check you package manager for gdb and clang++**
#### ubuntu/debian
`sudo apt install clang-11`\
`sudo apt install gdb`
#### manjaro/arch
`yay -S clang`\
`yay -S gdb`\
or install then manually [clang package](https://archlinux.org/packages/extra/x86_64/gdb/), [gbd package](https://archlinux.org/packages/extra/x86_64/clang/)
## Why
This template was made so you don't have to setup anything with almost everything work right out of the box!
