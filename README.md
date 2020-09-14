# smalltools

This repository contains a slowly growing collection of small apps and tools I have built for fun. Anything big will be moved to its own repository.

## What is here?

The following apps / tools are currently in this repository:

| Name    | CI                                                                                        | Description           |
|---------|-------------------------------------------------------------------------------------------|-----------------------|
| `clock` | ![Deploy docs](https://github.com/Ewpratten/smalltools/workflows/Build%20Clock/badge.svg) | A small CLI clock app |

## Building

This repo is built on top of the [Bazel build system](https://bazel.build). Any project can be compiled by running:

```sh
bazel build //appname
```

Where `appname` is the name of any of the apps listed above. The outputs will be generated in `bazel-bin` on your machine.