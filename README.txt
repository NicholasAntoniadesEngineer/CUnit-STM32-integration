

To add a pre build command for CUnit testing to the compiler of STM32H7 in STMCubeIDE:

1. Open your project in STMCubeIDE.
2. Right-click on your project in the Project Explorer, and select "Properties" from the context menu.
3. In the Properties window, navigate to "C/C++ Build" and click on "Settings".
4. Select the "Build Steps" tab.
5. Click on the "Add" button to add a new build step.
6. In the "Pre-build steps" field, enter the command for running your CUnit tests. This command may vary depending on your project structure and CUnit setup. Here's a sample command assuming you have a separate directory for your unit tests:
        cd ~/Documents/CUnit_testing/ && ./build.sh 
7. Click "Apply and Close" to save the changes and close the Properties window.
8. Build your project by selecting "Build Project" from the "Project" menu or pressing Ctrl+B.
