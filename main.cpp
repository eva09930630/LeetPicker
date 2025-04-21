#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>

struct Question {
    std::string id;
    std::string title;
    std::string url;
};

std::vector<Question> loadQuestionsFromCSV(const std::string& filename) {
    std::vector<Question> questions;
    std::ifstream file(filename);
    std::string line;
    Question q;

    if (!file.is_open()) {
        std::cerr << "無法開啟檔案：" << filename << std::endl;
        return questions;
    }

    std::getline(file, line); // 跳過第一行標題

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, title, url;
        std::getline(ss, id, ',');
        std::getline(ss, title, ',');
        std::getline(ss, url, ',');

        if (!id.empty() && !title.empty() && !url.empty()) {
            q.id = id;
            q.title = title;
            q.url = url;
            questions.push_back(q);
        }
    }

    file.close();
    return questions;
}

int main() {
    std::vector<Question> questions = loadQuestionsFromCSV("leetcode_questions.csv");

    if (questions.empty()) {
        std::cout << "題庫為空，請確認 leetcode_questions.csv 是否存在並有內容。\n";
        return 1;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int index = std::rand() % questions.size();

    Question q = questions[index];

    std::cout << "👾 今日推薦題目 👾\n";
    std::cout << "📌 題號：" << q.id << "\n";
    std::cout << "📚 標題：" << q.title << "\n";
    std::cout << "🔗 連結：" << q.url << "\n";

    return 0;
}
