This is a very simple program for parsing command options as bit flags. It only
supports up to 64 distinct flags, but that should be enough. Don't use
unprintable characters as flags. fo_parse, the function which does the flag
parsing, cannot do any handling of arguments associated with options. If you
want fancy options, don't use this. 
