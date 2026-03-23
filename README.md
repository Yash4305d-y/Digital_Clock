<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
</head>
<body>

<h1>⏰ Digital Clock (C)</h1>

<p>
This project is a Digital Clock built using the C programming language that displays
the current time in both <b>24-hour format</b> and <b>12-hour format (AM/PM)</b>.
</p>

<hr>

<h2>🚀 Features</h2>
<ul>
    <li>Displays real-time clock</li>
    <li>Supports 24-hour format</li>
    <li>Supports 12-hour format (AM/PM)</li>
    <li>Updates every second</li>
    <li>Lightweight and efficient</li>
</ul>

<hr>

<h2>📂 Project Structure</h2>
<pre>
project/
│
├── clock.c        # Main C program
└── README.html    # This file
</pre>

<hr>

<h2>⚙️ Requirements</h2>
<ul>
    <li>C compiler (GCC recommended)</li>
</ul>

<hr>

<h2>▶️ Usage</h2>

<h3>Compile the program:</h3>
<pre>
gcc clock.c -o clock
</pre>

<h3>Run the program:</h3>
<pre>
./clock
</pre>

<hr>

<h2>🧠 How It Works</h2>
<ul>
    <li>Uses <code>time.h</code> to fetch current system time</li>
    <li>Converts time into 12-hour and 24-hour formats</li>
    <li>Uses loop with delay to update every second</li>
</ul>

<hr>

<h2>📌 Example Code Snippet</h2>

<pre>
#include &lt;stdio.h&gt;
#include &lt;time.h&gt;
#include &lt;unistd.h&gt;

int main() {
    while (1) {
        time_t now;
        struct tm *local;

        time(&now);
        local = localtime(&now);

        // 24-hour format
        printf("24-Hour: %02d:%02d:%02d\n",
               local->tm_hour,
               local->tm_min,
               local->tm_sec);

        // 12-hour format
        int hour = local->tm_hour % 12;
        if (hour == 0) hour = 12;

        printf("12-Hour: %02d:%02d:%02d %s\n",
               hour,
               local->tm_min,
               local->tm_sec,
               (local->tm_hour >= 12) ? "PM" : "AM");

        sleep(1);
    }
    return 0;
}
</pre>

<hr>

<h2>📢 Notes</h2>
<ul>
    <li>Press <b>Ctrl + C</b> to stop the program</li>
    <li>Works on Linux/macOS (use <code>Sleep()</code> for Windows)</li>
</ul>

<hr>

<h2>📄 License</h2>
<p>This project is open-source and free to use.</p>

</body>
</html>
