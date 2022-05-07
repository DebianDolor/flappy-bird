# Flappy Bird
A C++ game using SDL2

# Main Screen
<p align="center">
  <img src="https://user-images.githubusercontent.com/78489381/167233797-8754cded-315a-4025-a9c9-9b2b52b94351.png" width=25% height=25%>
  <img src="https://user-images.githubusercontent.com/78489381/167233839-f2a41f56-1062-436f-9d60-a44f085f1ad9.png" width=25% height=25%>
  <img src="https://user-images.githubusercontent.com/78489381/167233860-c4164010-485e-442b-986f-ab9780e1ed4f.png" width=25% height=25%>
</p>

# Overview Structure
## Entity: 
Gồm các thực thể có trong màn hình bao gồm: Scoreboard & GameOver (PlayAgain button). </br>
Có các phương thức: </br>
1, updateScoreBoard(): update lại bảng scoreboard.</br>
2, updateGameOver()  : update GameOver.</br>
3, reset()           : reset lại các thực thể về hiện trạng ban đầu.</br>
## Score:   
Tính score, high score để hiển thị trên scoreboard.</br>
## Background:
Gồm hình nền city và ground.</br>
Có các phương thức: </br>
1, updateMainBg()        : update lại background city.</br>
2, updateBase()          : update lại ground (nền đất bên dưới cùng).</br>
3, updateBlendingDark()  : khi bird chết thì màn hình tối dần.</br>
4, updateBlendingLight() : khi bird chết thì màn hình sáng dần.</br>
5, reset()               : reset lại các thực thể về hiện trạng ban đầu.</br>
## Pipe:
Gồm 2 pipe có số thứ tự 0, 1 được render luân phiên.</br>
Có các phương thức: </br>
1, update(int index)               : update các pipe di chuyển dựa theo index (0 hoặc 1).</br>
2, getPipeRandom(int min, int max) : chọn các pipe 1 cách random để set moving pipe.</br>
3, reset()                         : reset lại các thực thể về hiện trạng ban đầu.</br>
## Bird: 
Tạo ra đối tượng bird và định nghĩa các phương thức jump, update (check xem có va chạm với pipe không).</br>
Các phương thức:  </br>
1, jump()                                     : định nghĩa phương thức nhảy của bird.</br>
2, getImgIndex()                              : chuyển các ảnh của bird.</br>
3, update(Pipe& b1, Pipe&b2, bool mainScreen) : check xem bird có va chạm với pipe không và dựa theo đó để xử lý.</br>
4, reset()                                    : reset lại các thực thể về hiện trạng ban đầu.</br>
## RenderWindow:
render màn hình và tất cả cá thực thể có trong màn hình gồm: mainscreen, background, scoreboard, bird, pipe.</br>
## Main:
Xử lý sự kiện chuột gồm: quit, play, playagain, control bird.</br>
Ngoài ra còn update Screen, render Screen, display Screen</br>
