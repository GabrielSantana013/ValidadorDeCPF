if #arg > 0 and (arg[1] == "--check" or arg[1] == "-c") then
    os.execute("cppcheck --suppress=missingIncludeSystem *.cpp");
end


os.execute("/usr/bin/g++ -Wall -Wextra -Werror -pedantic -g -fsanitize=address -O2 *.cpp");
