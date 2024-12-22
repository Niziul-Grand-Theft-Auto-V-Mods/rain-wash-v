<p align="right">
    <a href="https://wakatime.com/badge/user/62df9c07-c6d2-43a7-b767-6b968431c589/project/e7d46524-65fc-47f3-b4cd-d50eef0dc464" target="_blank">
        <img alt="Wakatime: Rain Wash V" src="https://wakatime.com/badge/user/62df9c07-c6d2-43a7-b767-6b968431c589/project/e7d46524-65fc-47f3-b4cd-d50eef0dc464.svg" />
    </a>
</p>

<p>
    <a href="https://www.gta5-mods.com/scripts/rain-wash-v#description_tab" target="_blank">
        <img alt="Rain Wash V" src="https://img.gta5-mods.com/q95/images/rain-wash-v/e96c9c-rain-wash-v-min.png" />
    </a>
</p>

<p><strong>About the mod</strong></p>
<p>This mod brings the effortless convenience of rain-washing away vehicle dirt. Enjoy the simplicity of maintaining a clean ride as rain showers automatically cleanse your vehicle's exterior, leaving it sparkling and spotless without any extra effort.</p>

<p><strong>Requisites</strong></p>
<ul>
    <li><a target="_blank" rel="noopener noreferrer" href="http://www.dev-c.com/gtav/scripthookv/">ScriptHookV - [v1.0.3179.0] or high</a></li>
</ul>

<p><strong>Featured</strong></p>
<ul>
    <li>Automatic Vehicle Cleaning: Rain showers automatically wash away dirt and grime from your vehicle's exterior without requiring manual input.</li>
</ul>

<p><strong>Build</strong></p>
<ol>
    <li>Configure the project using CMake:</li>
    <ul>
        <li><code>cmake -S . -B build -DCMAKE_BUILD_TYPE=Release</code></li>
    </ul>
    <li>Run the build process with MSBuild:</li>
    <ul>
        <li><code>cmake --build build --config Release</code></li>
    </ul>
    <li>Ensure all required libraries are present (e.g., <code>ScriptHookV.lib</code>).</li>
    <li>Add post-build commands in <code>CMakeLists.txt</code> to copy output files:</li>
    <li>Rebuild the project to apply changes:</li>
    <ul>
        <li><code>cmake --build build --config Release</code></li>
    </ul>
    <li>Verify the output in the target game directory and test functionality.</li>
</ol>

<p><strong>Installation</strong></p>
<ol>
    <li>Extract from the ".rar" the ".asi" file;</li>
    <li>Place the extracted file in your game's root directory (where you have installed GTAV);</li>
</ol>

<p><strong>Changelog</strong></p>
<ul>
    <li>[0.1.2.0]<ul>
            <li>Introduced a logging system to record details of nearby vehicles in a log file;</li>
            <li>Implemented a sorting mechanism for vehicles based on their distance from the player;</li>
            <li>Added a feature to clean multiple nearby vehicles dynamically based on rain and proximity;</li>
            <li>Optimized vehicle washing logic with the use of `std::max` for calculating dirt and decal levels;</li>
            <li>Enhanced error handling for entities that do not exist during vehicle processing;</li>
            <li>Implemented dynamic memory management for vehicle pool handling;</li>
            <li>Refactored code to improve modularity and readability by restructuring include paths and namespaces;</li>
        </ul>
    </li>
    <li>[0.1.1.0]<ul>
            <li>now cars clean up when stationary;</li>
        </ul>
    </li>
    <li>[0.1.0.0]<ul>
            <li>initial release;</li>
        </ul>
    </li>
</ul>
