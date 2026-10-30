#include <iostream>
#include <string>
#include <vector>

class BrowserHistoryStack {
private:
    std::vector<std::string> historyStack;
    std::string currentPage;

public:
    BrowserHistoryStack(const std::string& homePage = "portal.college.edu/home") {
        currentPage = homePage;
        historyStack.push_back(currentPage);
    }

    // a. Visit a new page (push URL)
    void visit(const std::string& url) {
        historyStack.push_back(url);
        currentPage = url;
        std::cout << "Visited: " << url << "\n";
    }

    // b. Go back to previous page (pop URL)
    void goBack() {
        if (historyStack.size() <= 1) {
            std::cout << "No previous page to go back to! (At initial page)\n";
            return;
        }
        std::string leavingPage = historyStack.back();
        historyStack.pop_back();
        currentPage = historyStack.back();
        std::cout << "Went back from [" << leavingPage << "] to [" << currentPage << "]\n";
    }

    // c. Display current page
    void showCurrentPage() const {
        std::cout << "Current Page: >>> " << currentPage << " <<<\n";
    }

    // d. Show entire browsing history stack
    void displayHistory() const {
        if (historyStack.empty()) {
            std::cout << "History is empty.\n";
            return;
        }

        std::cout << "\n============================================\n";
        std::cout << "    Browsing History Stack (Top to Bottom)  \n";
        std::cout << "============================================\n";
        for (int i = historyStack.size() - 1; i >= 0; --i) {
            if (i == static_cast<int>(historyStack.size() - 1)) {
                std::cout << " [TOP/CURRENT] -> " << historyStack[i] << "\n";
            } else {
                std::cout << "               -> " << historyStack[i] << "\n";
            }
        }
        std::cout << "============================================\n\n";
    }
};

int main() {
    BrowserHistoryStack browser("portal.college.edu/dashboard");

    browser.showCurrentPage();

    // a. Visit new pages
    browser.visit("portal.college.edu/attendance");
    browser.visit("portal.college.edu/marks");
    browser.visit("portal.college.edu/fees-payment");

    // c. Show current page
    browser.showCurrentPage();

    // d. Show full history stack
    browser.displayHistory();

    // b. Go back
    browser.goBack();
    browser.showCurrentPage();

    browser.goBack();
    browser.showCurrentPage();

    // d. Show updated history
    browser.displayHistory();

    return 0;
}
