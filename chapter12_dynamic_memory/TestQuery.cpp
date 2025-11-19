#include "TextQuery.h"

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <utility>

using std::size_t;
using std::shared_ptr;
using std::istringstream;
using std::string;
using std::getline;
using std::vector;
using std::map;
using std::set;
using std::cerr;
using std::cout;
using std::cin;
using std::ostream;
using std::endl;
using std::ifstream;
using std::ispunct;
using std::tolower;
using std::strlen;
using std::pair;


// type of the lookup map in a TextQuery object
typedef map<string, shared_ptr<set<TextQuery::line_no> > > wmType;

// the iterator type for the map
typedef wmType::const_iterator wmIter;

// type for the set that holds the line numbers
typedef shared_ptr<set<TextQuery::line_no> > lineType;

// iterator into the set
typedef set<TextQuery::line_no>::const_iterator lineIter;

TextQuery::TextQuery(ifstream &is) : file (new vector<string>)
{
    string text;
    while (getline(is, text))
    {
        file.push_back(text);
        int n = file.size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) 
        {
            word = cleanup_str(word);
            lineType &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

string TextQuery::cleanup_str(const string &word)
{
    string ret;
    for (auto it = word.begin(); it != word.end(); ++it)
    {
        if (!ispunct(*it))
            ret += towlower(*it);
    }
    return ret;
}

QueryResult
TextQuery::query (const string &sought) const
{
	// we'll return a pointer to this set if we don't find sought
	static lineType nodata(new set<line_no>); 

    // use find and not a subscript to avoid adding words to wm!
    wmIter loc = wm.find(cleanup_str(sought));

	if (loc == wm.end()) 
		return QueryResult(sought, nodata, file);  // not found
	else 
		return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << "time" << endl;

    // print each line in which the word appeared
	// for every element in the set 
	for (lineIter num = qr.lines->begin();
				num != qr.lines->end(); ++num) 
		// don't confound the user with text lines starting at 0
        os << "\t(line " << *num + 1 << ") " 
		   << qr.file.begin().deref(*num) << endl;
	return os;
}

