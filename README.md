# Flappy Bird
A C++ game using SDL2

# Main Screen
<p align="center">
  <img src="https://user-images.githubusercontent.com/78489381/167233797-8754cded-315a-4025-a9c9-9b2b52b94351.png" width=25% height=25%>
  <img src="https://user-images.githubusercontent.com/78489381/167233839-f2a41f56-1062-436f-9d60-a44f085f1ad9.png" width=25% height=25%>
  <img src="https://user-images.githubusercontent.com/78489381/167233860-c4164010-485e-442b-986f-ab9780e1ed4f.png" width=25% height=25%>
</p>

# Overview Structure
## Entity: Gồm các thực thể có trong màn hình bao gồm: Scoreboard & GameOver (PlayAgain button).
## Score: Tính score, high score để hiển thị trên scoreboard.
## Background: Gồm hình nền city và ground.
## Bird: Tạo ra đối tượng bird và định nghĩa các phương thức jump, check xem có va chạm với pipe không.
## RenderWindow: render màn hình và tất cả cá thực thể có trong màn hình gồm: mainscreen, background, scoreboard, bird, pipe.
## Main: xử lý sự kiện chuột gồm: quit, play, playagain, control bird.
