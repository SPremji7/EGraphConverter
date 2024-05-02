#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using namespace std;

string negative(string& subgraph){
  string temp;
  for (size_t i = 0; i < subgraph.length(); i++) {
    if (isalpha(subgraph[i])) {
      if(isupper(subgraph[i])){
        temp += tolower(subgraph[i]);
      }
      else{
        temp += toupper(subgraph[i]);
      }
      if (i<subgraph.length()-1) {
        if(isalpha(subgraph[i+1])){
          temp += "|";
        }
      }
    }
    if (subgraph.substr(i, 1)=="&") {
      temp += "|";
    }
    else if(subgraph.substr(i, 1)=="|"){
      temp += "&";
    }
  }
  return temp;
}


string parseGraph(string& graph){
  if (graph.length()==0) {
    return "";
  }
  
  string temp;
  if(isalpha(graph[0])){
    temp  = graph.substr(1, graph.length()-1);
    if(graph.length()==1){
      return graph.substr(0,1);
    }
    return graph.substr(0,1)+"&"+parseGraph(temp);
  }
  else if(graph.substr(0,1) =="(") {
    int open = 1;
    for (size_t i = 1; i < graph.length(); i++) {
      if (graph.substr(i,1)=="(") {
        open++;
      }
      else if(graph.substr(i,1)==")"){
        open--;
      }
      if(open==0){
        temp = graph.substr(1, i-1);
        string postTemp = graph.substr(i, graph.length()-i);
        temp = parseGraph(temp);
        if (postTemp.length()<=1) {
          return "["+negative(temp)+"]";
        }
        return "["+negative(temp)+"]&"+parseGraph(postTemp);
        
        
      }      
    }
  }
  else{
    temp = graph.substr(1, graph.length()-1);
    return parseGraph(temp);
  } 
  return "";
}  


string cleanUp(string& output){
    std::string result;
    for (char ch : output) {
        if (islower(ch)) {
            result += "\u00AC";
            result += toupper(ch);
        } 
        else if(ch == '&'){
          result+=" \u2227 ";
        }
        else if (ch=='|'){
          result+=" \u2228 ";
        }
        else {
          result += ch;
        }
    }
    return result;
}

string ifThen(string& output, string& pattern, string& replacement){
  std::regex re(pattern);
  return std::regex_replace(output, re, replacement);
}

int main(int argc, char* argv[]){
  cout<<"Input Graph\nFormat: (A(B))\n==>";
  string graph, output, outThen;
  cin>>graph;
  cout<<graph<<"\n";

  string pattern = "\\[\u00AC([A-Za-z]) \u2228 ([A-Za-z])\\]";
  string replacement = "[$1 \u27F6  $2]";

  output = parseGraph(graph);
  output = cleanUp(output);
  outThen = ifThen(output, pattern, replacement);

  cout<<"\n1)"<<output<<"\n";
  cout<<"2)"<<outThen<<"\n";

}