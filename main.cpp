/*
  yt++, a basic YouTube Content Save Tool.
  Copyright (C) 2022 Hamza Inan
  yt++ is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  yt++ is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
