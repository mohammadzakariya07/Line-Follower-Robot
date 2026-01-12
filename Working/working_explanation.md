# ⚙️ Working Explanation

The robot uses five IR sensors placed at the front.

- Each sensor detects black or white surface
- Black line gives LOW output
- Arduino checks sensor combination
- Based on position of line:
  - Center → Move Forward
  - Left → Turn Right
  - Right → Turn Left
- Near sensor stops the robot instantly

This logic allows smooth and accurate line following.
