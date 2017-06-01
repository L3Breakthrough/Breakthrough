#include <iostream>
#include <glog/logging.h> //Pour logs
using namespace std;

int main(int argc, char** argv){
	/// initialisation des logs
	google::SetLogDestination(google::GLOG_INFO, "log_breakthrough");
	google::InitGoogleLogging(argv[0]);
	cout<<"Hello World"<<endl;
return 0;
}
