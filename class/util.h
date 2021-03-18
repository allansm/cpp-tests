#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <iostream>

using namespace std;

class Util{
	
	Util(){
		
	}
	
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
	
	public : static string* split(string text, string delimiter){
        int lastSize = 0;
        int size = delimiterCount(text,delimiter);
        string* splited = new string[size];
        int i = 0;
        while(lastSize != text.length()){
            string temp = text.substr(0, text.find(delimiter));
            lastSize = text.length();
            splited[i++] = temp;
            text.erase(0,text.find(delimiter)+delimiter.length());
        }
        return splited;
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

    /*public : static string find(const string &s,const string &start_delim,const string &stop_delim){
        unsigned first_delim_pos = s.find(start_delim);
        unsigned end_pos_of_first_delim = first_delim_pos + start_delim.length();
        unsigned last_delim_pos = s.find_first_of(stop_delim, end_pos_of_first_delim);

        return s.substr(end_pos_of_first_delim,last_delim_pos - end_pos_of_first_delim);
    }*/
	
	//need fix
	/*public : static string find(string txt,string a,string b){
		string code = "<html><body><div><a><p></p></a></div></body></html>";
		code = "<a class=\"myclass\" href=\"http://localhost\"></a>";
		string found = "";
		//txt = code;
		//cout << txt << endl;
		int d1 = txt.find(a);
		cout << "d1:"<< d1 << endl;
		txt.erase(0,d1+a.length());
		//cout << txt << endl;
		int d2 = d1+a.length()+txt.find(b)+b.length();
		cout << "d2:"<< d2 << endl;
		int d1e = d1+a.length();

		int d2e = d2 - d1e;
		//string temp = "<a>";
		
		cout << "d1e:"<< d1e << endl;
		cout << "d2e:"<< d2e << endl;
		found = code.substr(d1e,d2);

		//string found = Util::find(code,"<html>","</html>");
		cout << found << endl;
		return found;
	}*/
	
	public : static string find(string txt,string a,string b){
		
		string found = "";
		
		int d1 = txt.find(a);
		
		txt.erase(0,d1+a.length());
	
		found = txt.substr(0,txt.find(b));
		
		return found;
	}
	public : static int delimiterCount(string txt,string a,string b){
		int i = 0;
		string prev = txt;
		string original = txt;
		while(txt != ""){
			string temp = find(txt,a,b);
			string erase = a+temp+b;
			txt.erase(0,txt.find(erase)+erase.length());
			if(original.find(erase) != -1){
				i++;
			}
		}
		return i;
	}

	public : static string* findAll(string txt,string a,string b){
		int size = delimiterCount(txt,a,b);
		string* arr = new string[size];
		string prev = txt;
		string original = txt;
		int i=0;
		while(txt != ""){
			string temp = find(txt,a,b);
			string erase = a+temp+b;
			txt.erase(0,txt.find(erase)+erase.length());
			if(original.find(erase) != -1){
				arr[i++] = temp;
			}
		}
		return arr;
	}


    public : static string replace(string txt,string toReplace,string newTxt){
        int start = txt.find(toReplace);
        int end = toReplace.length();
        return txt.replace(start,end,newTxt);
    }

    public : static void showAll(string txt,string deli1, string deli2){
        while(txt != ""){
            string found = Util::find(txt,deli1,deli2);
            cout << found << "\n";
            string complete = deli1+found+deli2;
            int start = txt.find(complete);
            int end = start+complete.length();
            txt.replace(start,end,"");
        }
    }
	
	
	//need fix
    /*public : static int countDeliO(string txt,string deli1, string deli2){
        int i=0;
		//try{
			while(txt != ""){
				//cout << txt << endl << endl;
				string found = Util::find(txt,deli1,deli2);
				cout << found << endl << endl;
				i++;
				string complete = deli1+found+deli2;
				cout << complete << endl;
				int start = txt.find(complete);
				int end = start+complete.length();
				txt.erase(0,end);
			}
		//}catch(const exception &e){}
		
        return i;
    }*/
	//this is wrong
	/*public : static string* findAll(string txt,string deli1, string deli2){
		int size = countDeliO(txt,deli1,deli2);
		string* all = new string[size];
		int i = 0;
		//try{
			while(txt != ""){
				cout << "reach this\n";
				string found = Util::find(txt,deli1,deli2);
				//if(found != "" && found != " "){
					cout << found << "\n";
					
					string complete = deli1+found+deli2;
					int start = txt.find(complete);
					int end = start+complete.length();
					//try{
						txt.erase(0,end);
						all[i++] = found;
					//}catch(const exception &e){break;}
				//}else{break;}
			}
		//}catch(const exception &e){}
		
		return all;
    }*/
	
	//need fix
	public : static int sizeOf(string* arr){
		/*int i = 0;
		string tmp = "";
		try{
			while(true){
				//try{
					tmp += arr[i++];
					cout << "reach this sizeof\n";
				//}catch(const exception e){
					//cerr << "error!!\n";
					//break;
				//}
			}
		}catch(const exception &e){
			
		}
		delete[] arr;
		//fix unkno error -2	
		//if(i != 0){
			//i-=2;
		//}
		//cout << i << "\n";
		tmp = "";*/
		int i = arr->size();
		return i;
	}

    public : string findAt(string txt,string deli1, string deli2,int i){
        int size = delimiterCount(txt,deli1,deli2);//countDeliO(txt,deli1,deli2);
        string temp[size];
        int ind =0;
        while(txt != ""){
            string found = Util::find(txt,deli1,deli2);
            temp[ind++] = found;
            string complete = deli1+found+deli2;
            int start = txt.find(complete);
            int end = start+complete.length();
            txt.replace(start,end,"");
        }
        return temp[i];
    }
    public : static string findAllInOne(string txt,string deli1, string deli2){
        string temp = "";
        while(txt != ""){
            try{
                string found = Util::find(txt,deli1,deli2);
                //cout << found << "\n";
                temp += found+"\n";
                string complete = deli1+found+deli2;
                int start = txt.find(complete);
                int end = start+complete.length();
                txt.replace(start,end,"");
            }catch (const exception &exc){
                break;
            }
        }
        return temp;
    }
	
	public : static string mergeString(string* arr,int size){
		string temp = "";
		
		
		//int size = arr->size();
		for(int i=0;i<size;i++){
			//try{
				temp+=arr[i];
				//cout << arr[i];
			//}catch(const exception &e){}
		}
		
		
		return temp;
	}
};

#endif // UTIL_H_INCLUDED
