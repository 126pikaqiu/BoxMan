#include "Session.h"
#include "console/ConsoleBoardUtil.h"

ConsoleBoardUtil consoleBoardUtil;
/**
 * paly one session
 * @param session the new session
 * @return if restart or not
 */
bool playOneSession(Session session){
    session.start();
    char order;
    while (!session.finished()) {
        consoleBoardUtil.display(session.getBoard());
        order = consoleBoardUtil.waitForInput(); // A W S D R Q
        if (order == 'R') {
            return true;
        } else if (order == 'Q') {
            consoleBoardUtil.giveUp();
            return false;
        }
        pair<Checkerboard, pair<int, int>> c = session.getPlayer().action(session.getBoard(), order);
        session.update(c);
    }
    consoleBoardUtil.display(session.getBoard());
    consoleBoardUtil.win();
    session.finish();
    return false;
}

int main() {
    consoleBoardUtil.welcome();
    Session session;
    string mapName("maps/");
    char level = consoleBoardUtil.pickLevel();
    mapName = mapName + level + ".map";
    session.loadMap(mapName);
    while (playOneSession(session)){
        session.loadMap(mapName);
    };
    return 0;
}
