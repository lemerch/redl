const {app, BrowserWindow} = require('electron')
let mainWindow
function createWindow () {
  mainWindow = new BrowserWindow({width: 300, height: 370,icon: __dirname + '/app_ico.ico',center: false,resizable: true});
  mainWindow.setMenuBarVisibility(false)
  mainWindow.loadFile('index.html')
  mainWindow.on('closed', function () {
    mainWindow = null
  })
}
app.on('ready', createWindow)
app.on('window-all-closed', function () {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})
app.on('activate', function () {
  if (mainWindow === null) {
    createWindow()
  }
})
const exec = require('child_process').exec;
function execute(command, callback) {
    exec(command, (error, stdout, stderr) => { 
        callback(stdout); 
    });
};
execute('mkdir TESTREDL', (output) => {
	console.log(output);
});
