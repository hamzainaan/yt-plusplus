//Simple YouTube video downloader in C++ by Hamza Inan using pytube library.
//You need to have Python and pytube
//For installation: python3 pip -m install pytube
//IMPORTANT: Please have the compiled program where you want to download the video. The program will download to whichever folder it is in.

#include <bits/stdc++.h>

std::string prepare_link(int type,std::string temp) {
   return (type=='a'||type=='A') ? "pytube " + temp + " -a" : (type=='v'||type=='V') ? "pytube " + temp : "Hata!";
}

int main(void) {

    //Get link from user.
    std::cout << "YouTube Link: ";
    std::string temp,link; std::cin >> temp;

    //Audio or video?
    std::cout << "Type (A/a for audio, V/v for video): ";
    char input; std::cin >> input;
    link = prepare_link(input,temp);

    //Basic exception handling.
    if(link == "Hata!") {
        exit(1);
    } else {
        //Because of the parameter type of system() function, we need to create pointer char.
        const char *cmd = link.c_str();
        system(cmd);
        system("clear");
    }

    return 0;
}