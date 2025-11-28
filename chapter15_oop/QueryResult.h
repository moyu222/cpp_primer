#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include <memory>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include "my_StrBlob.h"


class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &);
public:
    typedef std::vector<std::string>::size_type line_no;
    typedef std::set<line_no>::const_iterator line_it;

    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) :
        sought(s), lines(p), file(f) { }

    // QueryResult(std::string s,
    //             std::shared_ptr<std::set<line_no>> p,
    //             StrBlob f) : 
    //         sought(s), lines(p), file(f) { }

    std::set<line_no>::size_type size() const { return lines->size(); }
    line_it begin() const { return lines->begin(); }
    line_it end() const { return lines->end(); }
    std::shared_ptr<std::vector<std::string>> get_file() { return file; }
    // StrBlob get_file() { return file; }
    
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
    // StrBlob file;
};

std::ostream &print(std::ostream &, const QueryResult &);

#endif