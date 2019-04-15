#include "LinkedList.h"
#include <string>
#include <vector>
#include <fstream>
#include "Term.h"

using std::ifstream;
using std::string;
using std::vector;
using std::getline;

void ImportInformation(vector<string> &terms, vector<string> &definitions)
{
    ifstream file;
    file.open("Database.txt");
    
    if (file.is_open())
    {
        string word;
        string definition;
        bool cont = true;
        
        while (cont)
        {
            if (getline(file, word) && getline(file, definition))
            {
                cont = true;
                terms.push_back(word);
                definitions.push_back(definition);
            }
            else
                cont = false;
        }
    }
}

int main()
{
    LinkedList<Term> dictionary;
    vector<string> terms;
    vector<string> definitions;
    
    ImportInformation(terms, definitions);
    
    for (int i = 0; i < terms.size(); i++)
    {
        Term t(terms[i], definitions[i]);
        dictionary.Insert(t);
    }
    
    cout << dictionary << endl;
}
