#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include <iostream>
#include <sstream>

static const char *COMMA = " \t\n\r";
//static const char *UNEXPECTED_ARGS = "unexpected arguments";
//static const char *MISSING_ARGS = "missing arguments";

class Parser {
    public:
        Parser(std::string line) : arg1(""), arg2(""), arg3(""),
                                 arg4("") {
	        num_args = 0;
            std::stringstream is;	       
            trim_whitespace(line);
            is.str(line);
	        if (std::getline(is,arg1,',') && (++num_args))
                if (std::getline(is,arg2,',') && (++num_args))
                    if (std::getline(is,arg3,',')&& (++num_args)) {
                        getline(is, arg4);
                        arg4.erase(0,arg4.find_first_not_of(COMMA));
		                if (!arg4.empty()) ++num_args;
                    }
        }
        unsigned numArgs() const {return num_args;};
        std::string getArg1() {return arg1;};
        std::string getArg2() const {return arg2;};
        std::string getArg3() const {return arg3;};
        std::string getArg4() const {return arg4;};
      
        static std::string splitFirst(std::string &s) {
            s.erase(0, s.find_first_not_of(COMMA));
            std::string first;
            std::stringstream is(s);
            is >> first;
            s.erase(0, s.find_first_of(COMMA));
	        return first; 
        }

        static void trim_whitespace(std::string &s) {
            s.erase(0, s.find_first_not_of(COMMA));
            s.erase(s.find_last_not_of(COMMA) + 1);
        }

        static bool isInteger(const std::string &str) {
            for (const char &c : str)
                if (!std::isdigit(c)) 
	                return false;
            return true;
        }

    private:
        unsigned num_args;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
};

#endif