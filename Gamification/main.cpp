#include <QApplication>
#include "service/userService/UserService.h"
#include "gui/userGUI/UserWindow.h"
#include "service/loginService/LoginService.h"
#include "gui/loginGUI/LoginWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    std::string filePathQuests = "quests";
    std::string filePathUserStatus = "userStatus";
    std::string filePathUser = "users";

    auto *questsRepository = new TemplatedRepository<Quest>{filePathQuests};
    auto *userStatusRepository = new TemplatedRepository<UserStatus>{filePathUserStatus};
    auto *usersRepository = new TemplatedRepository<User>{filePathUser};

    auto *userService = new UserService{questsRepository, userStatusRepository};
    auto *loginService = new LoginService{usersRepository};

    auto *pp = new LoginWindow{userService, loginService};
    pp->setWindowTitle(QString::fromStdString("Login"));
    pp->show();

    return a.exec();
}
