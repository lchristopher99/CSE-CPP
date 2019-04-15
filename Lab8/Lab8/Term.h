#pragma once
#include <string>
#include <iostream>

using std::ostream;
using std::string;

class Term
{
private:
    string term;
    string definition;
    
public:
    Term(string t = "<None>", string d = "<None>")
    {
        term = t;
        definition = d;
    }
    
    bool operator<(const Term &rhs)
    {
        return (this->term < rhs.term);
    }
    
    bool operator>(const Term &rhs)
    {
        return (this->term > rhs.term);
    }
    
    bool operator<=(const Term &rhs)
    {
        return (this->term <= rhs.term);
    }
    
    bool operator>=(const Term &rhs)
    {
        return (this->term >= rhs.term);
    }
    
    bool operator==(const Term &rhs)
    {
        return (this->term == rhs.term);
    }
    
    friend ostream &operator<<(ostream &os, Term &obj)
    {
        os << obj.term << " - " << obj.definition;
        return os;
    }
};
