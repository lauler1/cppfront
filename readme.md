# CPPFRONT study


## Introduction

This is a simple repository for Cppfront study

It has two main folders:
 - cppfront/ The cppfront tool submodule from [github cppfront](https://github.com/hsutter/cppfront). Follow the instructions there.
 - proj/ A set of example projects in individual sub-folders. Each sub-folder contains a readme.md.

The `init.sh` is used to create the alias to call cppfront from any individual sub-folder. Run init.sh in any new terminal session before using cppfront.

```bash
$ source ./init.sh
or
$ . ./init.sh

```

You have to run with `source command` or `. ` from the base directory. When you execute a script in the normal way (without `source`), a new subshell (child shell) is forked, and the script runs in that subshell. Any variable set or modified in the script will not affect the calling (parent) shell.
When you use `source` or `. `, the script runs in the current shell. Any changes to variables or environment will persist even after the script completes.
