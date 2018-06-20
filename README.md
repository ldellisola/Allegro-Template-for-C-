Allegro Template for C++


As of now, it contains 3 versions of this template/wrapper for allegro 5.

- The first one, version 0, is a C template for some allegro 5 addons, including a main. This is no longer being updated.

- The second one, version 1, is a C++ quasi-wrapper for allegro 5. Similar to the first version, it allows you to initializate allegro and to only link the desired addons, but it is full of conditional compilation and thus it may be difficult to understand/mantain.

- The third one, version 2, is the latest and currently supported (and being developed) version of the wrapper. This is going to be a full wrapper around allegro. Right now i have some new data types such as WrittenBox, WritableBox and AllegroWindow that simplify the allegro code. I also implemented factories to make everything easier.

WrittenBox, WritableBox, allegroWindow and such files are not exclusive to Version 2, as the can be use independantly from any allegro wrapper.
