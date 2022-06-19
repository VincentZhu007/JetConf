# third_party module: jsoncpp
FetchContent_Declare(
    jsoncpp
    URL https://github.com/open-source-parsers/jsoncpp/archive/1.9.4.tar.gz
)

# Don't run jsconcpp test
set(JSONCPP_WITH_TESTS OFF)
FetchContent_MakeAvailable(jsoncpp)
