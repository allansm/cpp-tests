#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

class Util{
    public : static int delimiterCount(string text,string delimiter){
        int lastSize = 0;
        int count = 0;
        while(lastSize != text.length()){
            string temp = text.substr(0, text.find(delimiter));
            lastSize = text.length();
            text.erase(0,text.find(delimiter)+delimiter.length());
            count++;
        }
        return count;
    }
    public : static string split(string text, string delimiter,int index){
        int lastSize = 0;
        int size = delimiterCount(text,delimiter);
        string splited[size];
        int i = 0;
        while(lastSize != text.length()){
            string temp = text.substr(0, text.find(delimiter));
            lastSize = text.length();
            splited[i++] = temp;
            text.erase(0,text.find(delimiter)+delimiter.length());
        }
        return splited[index];
    }

    public : static int parseInt(string number){
        stringstream ss;
        int n = 0;
        ss.str(number);
        ss >> n;
        return n;
    }

    public : static string toString(int number){
        stringstream ss;
        string st;
        ss << number;
        ss >> st;
        return st;
    }

    public : static string test(const string &s,const string &start_delim,const string &stop_delim){
        unsigned first_delim_pos = s.find(start_delim);
        unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
        unsigned last_delim_pos = s.find_first_of(stop_delim, end_pos_of_first_delim);

        return s.substr(end_pos_of_first_delim,last_delim_pos - end_pos_of_first_delim);
    }
};

#endif // UTIL_H_INCLUDED
