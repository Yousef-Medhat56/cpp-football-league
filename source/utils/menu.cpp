#include "../../include/utils/menu.h"

void Menu::header()
{
    Console::clear();
    Console::divider();
    cout << "\tFootball League Simulation" << endl;
    Console::divider();
    cout << endl;
}

void Menu::main(League &league)
{
    Menu::header();
    cout << "1.Gameweeks\n"
         << "2.Standings Table\n"
         << "3.Statistics\n"
         << "4.Clubs Info\n"
         << "5.Players Info\n"
         << "0.exit\n"
         << "Enter your choice: ";

    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '1':
            gameweeks(league);
            break;
        case '2':
            standings(league);
            break;
        case '3':
            statistics(league);
            break;

        case '4':
            clubs(league);
            break;

        case '5':
            players(league);
            break;

        case '0':
            cout << 0 << endl;
            exit(1);

        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}

void Menu::gameweeks(League &league)
{
    int current_gameweek = league.getCurrentGameweekNum();
    int gameweeks_num = league.getGameweeksNum();
    Menu::header();
    cout << "1.Print Gameweeks Table\n";

    // if the league hasn't finished yet
    if (current_gameweek < gameweeks_num)
    {
        cout << "2.Enter Gameweek #" << current_gameweek + 1 << " results\n"
             << "3.Print Gameweek #" << current_gameweek + 1 << " matches\n";
    }

    cout << "0.Go back\n"
         << "Enter your choice: ";

    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '1':
            Menu::header();
            league.printGameweeksTable();

            // go back to the gameweeks menu
            Menu::footer(league, [](League &league)
                         { gameweeks(league); });
            break;
        case '2':
            if (current_gameweek < gameweeks_num)
            {
                Menu::header();
                league.enterCurrGameweekResults();
                
                Console::success("Gameweek #" + to_string(current_gameweek + 1) + " results have been entered successfully");
                // go back to the gameweeks menu
                Menu::footer(league, [](League &league)
                             { gameweeks(league); });
            }
            else
                exit_loop = false;
            break;
        case '3':
            if (current_gameweek < gameweeks_num)
            {
                Menu::header();
                league.getCurrentGameweek()->printMatches();

                Console::success("Gameweek #" + to_string(current_gameweek + 1) + " matches have been printed successfully");
                // go back to the gameweeks menu
                Menu::footer(league, [](League &league)
                             { gameweeks(league); });
            }
            else
                exit_loop = false;
            break;

        case '0':
            Menu::main(league);
            break;
        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}

void Menu::standings(League &league)
{
    Menu::header();
    league.printStandingsTable();
    // go back to the main menu
    Menu::footer(league, [](League &league)
                 { main(league); });
}

void Menu::statistics(League &league)
{
    Menu::header();
    //if the league hasn't started yet
    if (league.getCurrentGameweekNum() == 0)
    {
        //ask the user to enter the results of gameweek #1
        Console::error("Please enter results of Gameweek #1 first");
        // go back to the main menu
        Menu::footer(league, [](League &league)
                     { main(league); });
    }
    else
    {
        cout << "1.Print Best Goalkeepers\n"
             << "2.Print Best Defenders\n"
             << "3.Print Best Strikers\n"
             << "4.Print Top Carded Players\n"
             << "0.Go back\n"
             << "Enter your choice: ";

        bool exit_loop;
        do
        {
            exit_loop = true;
            switch (getch())
            {
            case '1':
                Menu::header();
                league.printTopGoalkeepers();

                // go back to the statistics menu
                Menu::footer(league, [](League &league)
                             { statistics(league); });
                break;
            case '2':
                Menu::header();
                league.printTopDefenders();

                // go back to the statistics menu
                Menu::footer(league, [](League &league)
                             { statistics(league); });
                break;
            case '3':
                Menu::header();
                league.printTopStrikers();

                // go back to the statistics menu
                Menu::footer(league, [](League &league)
                             { statistics(league); });
                break;
            case '4':
                Menu::header();
                league.printTopCarded();

                // go back to the statistics menu
                Menu::footer(league, [](League &league)
                             { statistics(league); });
                break;

            case '0':
                Menu::main(league);
                break;
            default:
                exit_loop = false;
            }
        } while (!exit_loop);
    }
}

void Menu::clubs(League &league)
{
    Menu::header();
    cout << "1.Print Clubs Info\n"
         << "2.Search for a club\n"
         << "0.Go back\n"
         << "Enter your choice: ";

    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '1':
            Menu::header();
            league.printClubsTable();

            // go back to the clubs menu
            Menu::footer(league, [](League &league)
                         { clubs(league); });
            break;
        case '2':
            Menu::header();
            league.searchForClub();

            // go back to the clubs menu
            Menu::footer(league, [](League &league)
                         { clubs(league); });
            break;

        case '0':
            Menu::main(league);
            break;
        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}
void Menu::players(League &league)
{
    Menu::header();
    cout << "1.Print Players Info\n"
         << "2.Search for a player\n"
         << "0.Go back\n"
         << "Enter your choice: ";

    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '1':
            Menu::header();
            league.printPlayersTable();

            // go back to the players menu
            Menu::footer(league, [](League &league)
                         { players(league); });
            break;
        case '2':
            Menu::header();
            league.searchForPlayer();

            // go back to the players menu
            Menu::footer(league, [](League &league)
                         { players(league); });
            break;

        case '0':
            Menu::main(league);
            break;
        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}

void Menu::footer(League &league, function<void(League &league)> func)
{
    cout << "Press 0 to go back\n";
    bool exit_loop;
    do
    {
        exit_loop = true;
        switch (getch())
        {
        case '0':
            func(league);
            break;
        default:
            exit_loop = false;
        }
    } while (!exit_loop);
}