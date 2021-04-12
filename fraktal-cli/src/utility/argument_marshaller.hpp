#pragma once

#include <string>

#include "enum_length.hpp"
#include "enum_to_string.hpp"

class ArgumentMarshaller {
  private:
    int argc;
    char **argv;

  public:
    ArgumentMarshaller(int argc, char *argv[]) {
        this->argc = argc;
        this->argv = argv;
    }

    int integerArgument(int expectedPosition, bool require = false) {
        if (argc >= expectedPosition + 1) {
            int argument = atoi(argv[expectedPosition]);

            return argument;
        }

        if (require) {
            exit(1);
        }

        return 0;
    }

    double doubleArgument(int expectedPosition, bool require = false) {
        if (argc >= expectedPosition + 1) {
            double argument = atof(argv[expectedPosition]);

            return argument;
        }

        if (require) {
            exit(1);
        }

        return 0;
    }

    std::string stringArgument(int expectedPosition, bool require = false) {
        if (argc >= expectedPosition + 1) {
            std::string argument = argv[expectedPosition];

            return argument;
        }

        if (require) {
            exit(1);
        }

        return "";
    }

    bool booleanArgument(int expectedPosition, bool require = false) {
        if (stringArgument(expectedPosition, require) == "true") {
            return true;
        }

        if (require) {
            exit(1);
        }

        return false;
    }

    template <typename T>
    T enumArgument(int expectedPosition, bool require = false) {
        std::string argument = stringArgument(expectedPosition, require);

        for (int i = 0; i <= enumLength<T>(); i++) {
            if (argument == enumToString<T>(static_cast<T>(i))) {
                return (T)i;
            }
        }

        if (require) {
            exit(1);
        }

        return (T)0;
    }
};