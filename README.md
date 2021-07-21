# Kernel Project:
This project has been separated from the boot-loader as I find it useful having them be separated. As this makes it easier for me to work on the code for each project and makes a much neater build environment for me.
___
# How to build:
### Simple Method:
To build this project please use the included make file and make sure that all tools below are installed. As these will be used by the make file during the process.

### Custom Method:
If make isn't available on your system you can compile manually by emulating the make commands on your system. You can also edit the make file should you want to use custom compilers/linkers. However if using a custom compiler and/or linker please mention this in any issues you report as this information could be useful in debugging if your build tools are different.
___

## Tools needed:
below are the tools that are used by the make file and that will be needed to build the target file. You shouldn't have to have these exact versions, however if there is a big difference in versions between my tools and yours and you have a issue while building please try using these versions of the tools just confirm it's not a version issue. Then feel free to report it to me once you've confirmed it's not a version issue.
- make (Version 4.3)
- clang (Version 12.0.0)
- ld.lld (Version 12.0.0)
- nasm (Version 2.15.05)
- coreutils mkdir/rm (Version 8.32)
___

## Building issues: 
if you encounter issues while building this code please check a few things first, make sure your are using the master branch and not the unstable branch. Try using the same version of tools that I'm using listed above. If neither of these helped you and you can't solve the problem on your own/don't know how to feel free to file a issue report on gitlab and I'll gladly look over the issue and try to work it out with you.
___

## Notice:
currently the project must be built with the UEFI boot-loader(project on my github) as it's boot-loader as of right now other boot-loaders are not supported though there are plans to allow more boot-loaders in the future.
___

# Contributing:
Help and code contributions are more than welcome. For small changes to the code base a pull request is sufficent for me to look over. For larger changes please open an issue to discuss exactly what you changed.

Please make sure to test your code before submitting a pull request or issue as I will be testing it as well, but it would help save my time if you confirm it definatly works how you want to it to before submitting.
___

# FAQ
Currently empty
___

# Branches:
- master a sort of stable branch that will be merged from unstable when I'm happy with what I've been working on in the unstable branch. Gives me a branch to fall back to if I mess up.
- unstable a branch where there is no guarantee anything will work and will be a reflection of what I'm currently working on.
