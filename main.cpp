
#include<bits/stdc++.h>
#include <io.h>
#include <dirent.h>

using namespace std;

typedef struct{
 string name;
 int lin;
}Node;
vector<Node>v;  //������ս��

void dir(string path,int l=0)
{
    vector<string> file;
    vector<string> folder;
    Node x;
    int lin;
    long hFile = 0;
    struct _finddata_t fileInfo;
    string pathName, exdName;
    if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(), &fileInfo)) == -1) {
        cout<<"Not find the path or file"<<endl;
        return;
    }
    do
    {
        if(fileInfo.attrib&_A_SUBDIR)
            folder.push_back(fileInfo.name);
        else
             file.push_back(fileInfo.name);

    } while (_findnext(hFile, &fileInfo) == 0);
    _findclose(hFile);

    x.lin=l;
     int t=1;
    if(!file.empty())
        for(auto i :file){
            x.name=std::to_string(t++);
             x.name+="��  "+i;
            v.push_back(x);
        }
        t=1;
    if(!folder.empty())
        for(int i=0;i<folder.size();i++){
            if(i<2) continue;
            x.name=std::to_string(t++);
             x.name+="��  "+folder[i];
            v.push_back(x);
        }
        t=1;
        for(int i=0;i<folder.size();i++){
            if(i<2) continue;
            x.name=std::to_string(t++);
             x.name+="�� folder: "+folder[i];
            v.push_back(x);
           dir(path+"\\"+folder[i],l+1);
        }
}

int main(){
  string path;
  string s;
  FILE *fp = NULL;
  cout<<"�������ļ��е�ַ(��껬���˵��Զ�����ַ���Ҽ�ѡ�񡰽���ַ����Ϊ�ı�����ճ�����˴���Ȼ��Enter)��"<<endl;
  cin>>path;
  dir(path);

   if(v.empty()) return 1;
  //д��Ŀ¼�ļ�
   s=path+"\\Ŀ¼.txt";
   fp = fopen(s.c_str(), "w");
   for(auto i:v){
    s="";
    for(int j=0;j<i.lin;j++) s+="-";
    s+=i.name+"\n";
    fputs(s.c_str(), fp);
  }
   fclose(fp);
   cout<<path+"\\Ŀ¼.txt"+"�ļ������ɣ�\n�������£�"<<endl;
  //��ӡ���
  for(auto i:v){
    for(int j=0;j<i.lin;j++) cout<<"-";
    cout<<i.name<<endl;
  }
  cout<<"���������ַ��رձ�ҳ��"<<endl;
  cin>>s;
 return 0;
}


