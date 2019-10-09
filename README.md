This is a QT program compiled from the terminal.
The following steps were made:

1. $ qmake -project // For .pro file creation

2. .pro file edit for QT += gui widgets

3. qmake .pro // To make the project platform specific

Missing only the final "make" that is done inside a Docker container.
