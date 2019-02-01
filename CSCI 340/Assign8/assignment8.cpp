#include "assignment8.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//This gets the entry key used to rebuld the htable
Entry* get_entry(const string& line)
{
   Entry* parsed_line = new Entry;
   parsed_line->key = line.substr(2, 3);
   parsed_line->description = line.substr(6, line.length() - 6);
   return parsed_line;
}

//This actually recevies the key to be used
string get_key(const string& line)
{
   string gKey = line.substr(2, 3);
   return gKey;
}

//This creates the table to be used and sets the settings.
HT::HT(int s = 11)
{
   hTable = new vector<Entry>(s);
   table_size = s;
   item_count = 0;
}

//This resets the table so we can rebuild and refill it with numbers
HT::~HT()
{
   delete hTable;
}

//This uses a serach pattern to be used and set to the current path to find the key.
int HT::search (const string& key)
{
   int keyIndex = hashing(key);
   for(int i = 0; i < table_size; i++) {
       if ((*hTable)[keyIndex].key == key)
           return keyIndex;
       keyIndex = (keyIndex + 1) % table_size;
   }
   return -1;
}

//This inserts the keys and table data to be processed
bool HT::insert(const Entry& e)
{
   int keyIndex = hashing(e.key);
   string sKey = e.key;
   if (search(sKey) != -1) {
       cerr << "Unable to insert - identical key found" << endl;
       return false;
   }
   else if (item_count == table_size) {
       cerr << "Unable to insert - the table is full." << endl;
       return false;
   }
   else {
       int i;
       for (i = 0; i < table_size; i++) {
           if ((*hTable)[keyIndex].key == "---" || (*hTable)[keyIndex].key == "+++") {
               (*hTable)[keyIndex] = e;
               item_count++;

               return true;
           }
           keyIndex = keyIndex + 1 % table_size;
       }
   }
   return false;
}

//This removes the itesm froma table when call
bool HT::remove(const string& s)
{
   if (search(s) == -1) {
       return false;
   }
   else {
       int keyIndex = search(s);

       (*hTable)[keyIndex].key = "+++";
       item_count--;
       return true;
   }
}

//This will print out the table that  is given to you
void HT::print ()
{
   cout << endl << "----Hash Table-----" << endl;

   for (int i = 0; i < table_size; i++) {
       if ((*hTable)[i].key != "---" && (*hTable)[i].key != "+++") {
           cout << right << setw(2) << i << ": ";
           cout << (*hTable)[i].key << " ";
           cout << (*hTable)[i].description << endl;
       }
   }
   cout << "---------------------------" << endl << endl;
}

//This hashes all the keys to a ceratin pattern already done for you.
int HT::hashing(const string& key) {
   return ((int)key[0] + (int)key[1] + (int)key[2])%table_size;
}

int main(int argc, char** argv) {
   HT ht;
   ifstream infile("input.txt", ios::in);
   string line;
   infile >> line;
   while (!infile.eof()) {
       if (line[0] == 'A') {
           Entry* e = get_entry(line);
           ht.insert(*e);
           delete e;
       }
       else {
           string key = get_key(line);
           if (line[0] == 'D') {
               cout << "Removing " << key << "...\n";
               bool removed = ht.remove(key);
               if (removed)
                   cout << key << " is removed successfully...\n\n";
               else
                   cout << key << " does not exist, no key is removed...\n\n";
           }
           else if (line[0] == 'S') {
               int found = ht.search(key);
               if (found < 0)
                   cout << key << " does not exit in the hash table ..." << endl << endl;
               else
                   cout << key << " is found at table position " << found << endl << endl;
           }
           else if (line[0] == 'P') {
               cout << "\nDisplaying the table: " << endl;
               ht.print();
           }
           else
               cerr << "wrong input: " << line << endl;
       }
       infile >> line;

   }

   infile.close();
   return 0;
}