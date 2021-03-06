
//

#ifndef __GameAppH__
#define __GameAppH__

#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QKeyEvent>
#include <QTimer>
#include <QThread>
#include <QMutex>

#include "Qt/ConsoleViewerGL.h"
#include "Qt/ConsoleViewerSDL.h"
#include "Qt/GamePadConf.h"

class  emulatorThread_t : public QThread
{
	Q_OBJECT

	//public slots:
		void run( void ) override;
	signals:
    void finished();
};

class  consoleWin_t : public QMainWindow
{
	Q_OBJECT

	public:
		consoleWin_t(QWidget *parent = 0);
	   ~consoleWin_t(void);

		ConsoleViewGL_t *viewport;
		//ConsoleViewSDL_t *viewport;

		void setCyclePeriodms( int ms );

		QMutex *mutex;

	protected:
	 QMenu *fileMenu;
    QMenu *optMenu;
    QMenu *emuMenu;
    QMenu *movieMenu;
    QMenu *helpMenu;

    QAction *openROM;
    QAction *closeROM;
    QAction *playNSF;
    QAction *loadStateAct;
    QAction *saveStateAct;
    QAction *quickLoadAct;
    QAction *quickSaveAct;
    QAction *loadLuaAct;
    QAction *scrShotAct;
    QAction *quitAct;
    QAction *gamePadConfig;
    QAction *gameSoundConfig;
    QAction *gameVideoConfig;
    QAction *hotkeyConfig;
    QAction *autoResume;
    QAction *fullscreen;
    QAction *aboutAct;
	 QAction *state[10];
	 QAction *powerAct;
	 QAction *resetAct;
	 QAction *sresetAct;
	 QAction *pauseAct;
	 QAction *gameGenieAct;
	 QAction *loadGgROMAct;
	 QAction *insCoinAct;
	 QAction *fdsSwitchAct;
	 QAction *fdsEjectAct;
	 QAction *fdsLoadBiosAct;
	 QAction *openMovAct;
	 QAction *stopMovAct;
	 QAction *recMovAct;
	 QAction *recAsMovAct;

	 QTimer  *gameTimer;
	 emulatorThread_t *emulatorThread;

    GamePadConfDialog_t *gamePadConfWin;

	protected:
    void closeEvent(QCloseEvent *event);
	 void keyPressEvent(QKeyEvent *event);
	 void keyReleaseEvent(QKeyEvent *event);
	 void syncActionConfig( QAction *act, const char *property );

	 int  getDirFromFile( const char *path, char *dir );

	private:
		void createMainMenu(void);

	private slots:
		void closeApp(void);
		void openROMFile(void);
		void loadNSF(void);
		void loadStateFrom(void);
		void saveStateAs(void);
		void quickLoad(void);
		void quickSave(void);
		void closeROMCB(void);
      void aboutFCEUX(void);
      void openGamePadConfWin(void);
      void openGameSndConfWin(void);
      void openGameVideoConfWin(void);
      void openHotkeyConfWin(void);
      void toggleAutoResume(void);
      void toggleFullscreen(void);
      void updatePeriodic(void);
      void changeState0(void);
      void changeState1(void);
      void changeState2(void);
      void changeState3(void);
      void changeState4(void);
      void changeState5(void);
      void changeState6(void);
      void changeState7(void);
      void changeState8(void);
      void changeState9(void);
      void loadLua(void);
      void takeScreenShot(void);
      void powerConsoleCB(void);
		void consoleHardReset(void);
		void consoleSoftReset(void);
		void consolePause(void);
		void toggleGameGenie(bool checked);
		void loadGameGenieROM(void);
		void insertCoin(void);
		void fdsSwitchDisk(void);
		void fdsEjectDisk(void);
		void fdsLoadBiosFile(void);
		void openMovie(void);
		void stopMovie(void);
		void recordMovie(void);
		void recordMovieAs(void);

};

extern consoleWin_t *consoleWindow;

#endif
