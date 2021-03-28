/*********************************************************************
*                                                                    *
*   Copyright 2012 - dLogic (www.dLogic.com). All rights reserved.   *
*   TrondAre [2012.04]                                               *
*                                                                    *
*********************************************************************/
#ifndef STYLE_H
#define STYLE_H

#include <QString>
#include <QMap>

namespace Ui {

class Styles;

enum LAYOUT { HORIZONTAL, VERTICAL };

static QString PBTN_YESQBUTTON = " \
        QPushButton { \
            border:none; \
            background:none; \
            font-size:20px;  \
            font-family: 'breuertextbold'; \
        } \
        QPushButton:pressed  { \
            border:none; \
            background:none;  \
            font-size:20px; \
            font-family: 'breuertextbold'; \
        }";

static QString PBTN_SWIPSVCSTARTBUTTON = " \
        QPushButton { \
            border:none; \
            background:none; \
            font-size:20px;  \
            font-family: 'breuertextbold'; \
        } \
        QPushButton:pressed  { \
            border:none; \
            background:none;  \
            font-size:20px; \
            font-family: 'breuertextbold'; \
        }";

static QString PBTN_COURIERSCREENPARCELBUTTON = " \
        QPushButton { \
            border-radius: 4px; \
            border-width: 0px; \
            border-color: rgb(0, 0, 0); \
            border-style: outset; \
            font-size: 36px; \
            color: white; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #01B4CF stop: 1 #15C8E2); \
            font-family: 'breuertextbold'; \
        } \
        QPushButton:pressed { \
            border-radius: 4px; \
            border-width: 0px; \
            border-color: rgb(0, 0, 0); \
            border-style: outset; \
            font-size: 36px; \
            color: white; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #15C8E2, stop: 1 #01B4CF); \
            font-family: 'breuertextbold'; \
        }";



static QString CHECKBOX_STYLE = " \
        QCheckBox{ \
            border-radius: 4px; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #F5F5F5 stop: 1 #FFFFFF); \
        } \
        QCheckBox::indicator:unchecked { \
            image: url(:/BlueBoxImageList/EndUserForms/images/Unchecked.png); \
        } \
        QCheckBox::indicator:checked { \
            image: url(:/BlueBoxImageList/EndUserForms/images/Checked.png); \
        }";

static QString LBL_TRANSPARENT_BACK = " \
        QLabel { \
            font: 16pt \"FreeSans\"; \
            color: black; \
            background: none; \
            border: none; \
        }";

static QString MAIN_WINDOW_STYLE = " \
        QMainWindow { \
            background-color:#E7E7E7; \
            border-color:green; \
        }";

static QString TEST_APP_BACKGROUND = " \
        background-color:#B4B4B4 \
        ";

static QString WIN_GRAY_BACKGROUND = "background-color:#F5F5F5";

static QString WIN_WHITE_BACKGROUND = "background-color:#fff";

static QString TABLE_WIDGET_STYLE = " \
        QTableWidget { \
            font-family: 'breuer_text_light'; \
            font-size:20px; \
            background-color: #B4B4B4 \
        } \
        QHeaderView::section { \
            font-family: 'breuer_text_light'; \
            font-size:20px; \
            background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,  stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565); \
            color: white; \
            padding-left: 4px; \
            height : 35px; \
            border: 1px solid #6c6c6c; \
        } \
        QTableWidget::item { \
            height : 60px; \
        } \
        QScrollBar:vertical { \
            border: 2px solid grey; \
            background: white; \
            width: 45px; \
        } \
        QScrollBar:horizontal { \
            border: 2px solid grey; \
            background: white; \
            height: 45px; \
        }";

static QString LBL_HEADING = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:48px; \
            padding:0px; \
            margin:0px; \
        }";

static QString LBL_SUB_HEADING_WHITE = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:32px; \
            padding:0px; \
            margin:0px; \
            background-color:#fff \
        }";

static QString LBL_SUB_HEADING = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:32px; \
            padding:0px; \
            margin:0px; \
        }";

static QString LBL_SUB_HEADING_30 = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:30px; \
            padding:0px; \
            margin:0px; \
        }";

static QString LBL_TEXT = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:22px; \
            padding:0px; \
            margin:0px; \
        }";

static QString LBL_TEXT_LARGE = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:28px; \
            padding:0px; \
            margin:0px; \
        }";

static QString LBL_TEXT_26 = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:26px; \
            padding:0px; \
            margin:0px; \
        }";

static QString LBL_TEXT_28 = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:28px; \
            padding:0px; \
            margin:0px; \
        }";

static QString LBL_TEXT_30 = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:30px; \
            padding:0px; \
            margin:0px; \
        }";

static QString LBL_TEXT_27 = " \
        QLabel { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font:bold 27px; \
            padding:0px; \
            margin:0px; \
        }";
static QString LBL_TEXT_16 = " \
        QLabel { \
            color:#000000; \
            font-family: 'breuer_text_lightbold'; \
            font-size:16px; \
            padding:0px; \
            margin:0px; \
        }";

static QString LBL_TEXT_20 = " \
        QLabel { \
            color:#00000; \
            font-family: 'breuer_text_lightbold'; \
            font-size:20px; \
            padding:0px; \
            margin:0px; \
        }";



static QString TAB_STYLE = " \
        QTabWidget::tab-bar { \
        } \
        QTabBar::tab { \
            background: lightgray; \
            color: black; \
            padding: 10px; \
        } \
        QTabBar::tab:selected {  \
            background: gray; \
        } \ ";

static QString TXTEDIT_SCROLLBARS=    " \
        QScrollBar:vertical { \
            border: 2px solid grey; \
            background: white; \
            width: 45px; \
         } \
        QScrollBar:horizontal { \
            border: 2px solid grey; \
            background: white; \
            height: 45px; \
        }";

static QString PBTN_SWIPBUTTON_18 = " \
        QPushButton { \
            font-family: 'breuertextbold'; \
            font-size: 18px; \
            border-color: rgb(0, 0, 0); \
            border-style: none; \
            border-radius: 4px; \
            border-width: 0px; \
            border-bottom:solid #9A9797; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #F5F5F5 stop: 1 #FFFFFF); \
        } \
        QPushButton:pressed { \
            font-family: 'breuertextbold'; \
            font-size: 18px; \
            border-color: rgb(0, 0, 0); \
            border-style: outset; \
            border-radius: 4px; \
            border-width: 0px; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFFFFF, stop: 1 #F5F5F5); \
        }";

static QString PBTN_SWIPBUTTON_8 = " \
        QPushButton { \
            font-family: 'breuertextbold'; \
            font-size: 18px; \
            border-color: rgb(0, 0, 0); \
            border-style: none; \
            border-radius: 4px; \
            border-width: 0px; \
            border-bottom:solid #9A9797; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #F5F5F5 stop: 1 #FFFFFF); \
        } \
        QPushButton:pressed { \
            font-family: 'breuertextbold'; \
            font-size: 18px; \
            border-color: rgb(0, 0, 0); \
            border-style: outset; \
            border-radius: 4px; \
            border-width: 0px; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFFFFF, stop: 1 #F5F5F5); \
        }";

static QString PBTN_SWIPBUTTON = " \
        QPushButton { \
            font-family: 'breuertextbold'; \
            font-size: 36px; \
            border-color: rgb(0, 0, 0); \
            border-style: none; \
            border-radius: 4px; \
            border-width: 0px; \
            border-bottom:solid #9A9797; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #F5F5F5 stop: 1 #FFFFFF); \
        } \
        QPushButton:pressed { \
            font-family: 'breuertextbold'; \
            font-size: 36px; \
            border-color: rgb(0, 0, 0); \
            border-style: outset; \
            border-radius: 4px; \
            border-width: 0px; \
            background-color: #19B5CF; \
        }";

static QString PBTN_SWIPBUTTON_GREEN = " \
        QPushButton { \
            color : green; \
            font-family: 'breuertextbold'; \
            font-size: 36px; \
            border-color: rgb(0, 0, 0); \
            border-style: none; \
            border-radius: 4px; \
            border-width: 0px; \
            border-bottom:solid #9A9797; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #F5F5F5 stop: 1 #FFFFFF); \
        } \
        QPushButton:pressed { \
            color : green;  \
            font-family: 'breuertextbold'; \
            font-size: 36px; \
            border-color: rgb(0, 0, 0); \
            border-style: outset; \
            border-radius: 4px; \
            border-width: 0px; \
            background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #FFFFFF, stop: 1 #F5F5F5); \
        }";

static QString PBTN_ORANGE = " \
        QPushButton { \
            border:5px solid #fff; \
            background-color:#fc5622; \
            font-size:28px;  \
            font-family: 'breuertextbold'; \
        } \
        QPushButton:pressed  { \
            border:5px solid #fc5622; \
            background-color:#ffffff; \
            font-size:28px; \
            font-family: 'breuertextbold'; \
   }";

static QString PBTN_SWIP_TEST = " \
        QPushButton { \
            border:5px solid #fff; \
            background-color:#0fc6e2; \
            font-size:28px;  \
            font-family: 'breuertextbold'; \
            border-bottom:solid #9A9797; \
        } \
        QPushButton:pressed  { \
            border:5px solid #0fc6e2; \
            background-color:#ffffff;  \
            font-size:28px; \
            font-family: 'breuertextbold'; \
        }";

static QString PBTN_BLUE = " \
        QPushButton { \
            border:5px solid #fff; \
            background-color:#0fc6e2; \
            font-size:28px;  \
            font-family: 'breuertextbold'; \
        } \
        QPushButton:pressed  { \
            border:5px solid #0fc6e2; \
            background-color:#ffffff;  \
            font-size:28px; \
            font-family: 'breuertextbold'; \
        }";

static QString PBTN_BLUE_BBLACK = " \
        QPushButton { \
            color : #000000; \
            border:5px solid #FFFFFF; \
            background-color:#0fc6e2; \
            font-size:24px;  \
            font-family: 'breuertextbold'; \
        } \
        QPushButton:pressed  { \
            border:5px solid #0fc6e2; \
            background-color:#ffffff;  \
            font-size:28px; \
            font-family: 'breuertextbold'; \
        }";

static QString LBL_BLACK_OFFSET_ORANGE_48_GREY4PX = " \
        QLabel { \
            font: 48pt \"FreeSans\"; \
            color: orange; \
            background: #303030; \
            border-color: grey; \
            border-style: outset; \
            border-radius: 8px; \
            border-width: 4px; \
        }";

static QString LBL_CODE_STYLE_WHITE_44 = " \
        QLabel { \
            border-radius: 2px; \
            border:1px solid #F0A804;  \
            background: #FFFFFF; \
            height:58px; \
            padding:100px; \
            font: bold 44px; \
            font-family: 'breuer_text_lightbold'; \
            color:#000; \
        }";

static QString LBL_CODE_STYLE_WHITE_26 = " \
        QLabel { \
            border:1px solid #D3D3D3;  \
            background: #FFFFFF; \
            font-size:28px; \
            height:58px; \
            padding:10px; \
            font-family: 'breuer_text_lightbold'; \
            color:#000; \
        }";

static QString LBL_CODE_STYLE_28 = " \
        QLabel { \
            border-radius: 8px; \
            border:none;  \
            background: none; \
            font-size:28px; \
            height:58px; \
            padding:10px; \
            font-family: 'breuer_text_lightbold'; \
            color:#ffffff; \
            background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,  stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565); \
        }";

static QString LBL_CODE_STYLE_20 = " \
        QLabel { \
            border-radius: 8px; \
            border:none;  \
            background: none; \
            font-size:20px; \
            height:58px; \
            padding:2px; \
            font-family: 'breuer_text_light'; \
            color:#ffffff; \
            background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,  stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565); \
        }";

static QString LBL_CODE_STYLE = " \
        QLabel { \
            border-radius: 8px; \
            border:none;  \
            background: none; \
            font-size:40px; \
            height:58px; \
            padding:10px; \
            font-family: 'breuer_text_lightbold'; \
            color:#ffffff; \
            background-color: qlineargradient(x1:0, y1:0, x2:0, y2:1,  stop:0 #616161, stop: 0.5 #505050, stop: 0.6 #434343, stop:1 #656565); \
        }";

static QString LBL_TRANSPARENT = " \
        QLabel { \
            font: 16pt \"FreeSans\"; \
            color: white; \
            background: none; \
            border: none; \
        }";

static QString LBL_TRANSPARENT_GREY4PX = " \
        QLabel { \
            background: none; \
            border-color: grey; \
            border-style: outset; \
            border-radius: 8px; \
            border-width: 4px; \
        }";

static QString FRAME_YELLOW = " \
        QFrame { \
            background-color: yellow; \
        }";


static QString BUTTON_TRANSPARENT = " \
        QPushButton { \
            color: white; \
            background: none; \
            border: none; \
        } \
        QPushButton:pressed {       \
            background: none;   \
            border: none;\
        }";


static QString LCD_TEXT = " \
        QLCDNumber { \
            color:#323232; \
            font-family: 'breuer_text_lightbold'; \
            font-size:22px; \
            padding:0px; \
            margin:0px; \
        }";

}

class Styles
{
public:
//  static QString SelectButtonWidget_Btn_Unselected_Right;

private:
    typedef QMap<QString, QString> StylesContainer;	// <name, style>
    typedef StylesContainer::iterator StylesContainerIterator;

    StylesContainer mc_styles;
    StylesContainerIterator	mi_styles;

public:
    static Styles* instance()
    {
        static Styles instance;
        return &instance;
    }

    QString style(QString &name)
    {
        mi_styles = mc_styles.find(name);
        return ( mi_styles != mc_styles.end() ) ? mi_styles.value() : 0;
    }

private:
    Styles() {}

    // Not implemented/defined
    Styles (const Styles& src);				// inhibit accidental copy
    Styles& operator=(const Styles& rhs);	// inhibit accidental assignment
};

//  QString Styles::SelectButtonWidget_Btn_Unselected_Right = "";

//  background-color: QLinearGradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #0000FF, stop: 0.33 #000080, stop: 0.5 000040 stop: 0.66 000080 stop: 1 #0000FF); \

#endif // STYLE_H
