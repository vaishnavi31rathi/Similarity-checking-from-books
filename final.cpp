src/main.cpp
Original file line number	Diff line number	Diff line change
@@ -171,6 +171,12 @@ class BookComparison
    void findMostUsedWords()
    {   
        cout<<"Finding the most used words..."<<endl;

        // Open output file
        ofstream outFile("outputFiles/common_words.txt");
        outFile << "📚 Most Common Words in Each Book 📚\n";
        outFile << "=================================\n\n";

        for (const auto &book : bookWordsNormalScore)
        {
            // Create list of pairs to sort by normal score
@@ -192,29 +198,56 @@ class BookComparison
            int count = 0;
            int numWords = min(100, static_cast<int>(wordScores.size()));

            // Write book title to file
            outFile << "📖 " << book.first << "\n";
            outFile << string(80, '-') << "\n";
            outFile << "Top " << numWords << " most frequent words:\n\n";

            for (const auto &wordScore : wordScores)
            {
                if (count >= numWords)
                    break;
                topWords.push_back(wordScore.first);

                // Write word and its frequency to file
                outFile << count + 1 << ". " 
                        << left << wordScore.first 
                       << " (Frequency: "
                       << wordScore.second << ")\n";
                count++;
            }

            // Store in mostUsedWords map
            mostUsedWords[book.first] = topWords;

            outFile << "\n\n";
        }
        cout<<"Most used words have been found!"<<endl;

        outFile.close();
        cout<<"Most used words have been found and written to outputFiles/common_words.txt!"<<endl;
        cout<<endl;
    }
    void compareBooks()
    {
        cout<<"Comparing books..."<<endl;
        cout << "Comparing books..." << endl;
        cout << "\nBook Similarities:\n";

        // Open file for writing similarity matrix
        ofstream outFile("outputFiles/similarity_matrix.txt");
        if (!outFile.is_open()) {
            cout << "Error opening outputFiles/similarity_matrix.txt for writing" << endl;
            return;
        }

        // Get list of all book names
        vector<string> bookNames;
        for (const auto &book : mostUsedWords) {
            bookNames.push_back(book.first);
        }

        // Write header to file
        outFile << "📊 Book Similarity Matrix" << endl;
        outFile << string(100, '=') << endl << endl;

        // Compare each book with others (avoiding duplicates and self-comparisons)
        for (size_t i = 0; i < bookNames.size(); i++) {
@@ -240,18 +273,22 @@ class BookComparison
                string bookPairKey = book1 + " and " + book2;
                bookSimilarities[bookPairKey] = similarityIndex;

                cout<<bookPairKey<<" : "<<similarityIndex<<endl;
                // Write to console
                cout << bookPairKey << " : " << similarityIndex << endl;

                // Write to file with formatting
                outFile << "📚 Book Pair #" << (i * bookNames.size() + j + 1) << endl;
                outFile << "├─ Book 1: " << book1 << endl;
                outFile << "├─ Book 2: " << book2 << endl;
                outFile << "└─ Similarity Index: " << similarityIndex << endl;
                outFile << string(80, '-') << endl << endl;
            }
        }

        // // Display results
        // cout << "\nBook Similarities:\n";
        // for (const auto &similarity : bookSimilarities) {
        //     cout << similarity.first << ": " << similarity.second << endl;
        // }

        cout<<"All the books have been compared!"<<endl;
        cout<<endl;
        outFile.close();
        cout << "All the books have been compared!" << endl;
        cout << "Similarity matrix has been written to outputFiles/similarity_matrix.txt" << endl;
        cout << endl;
    }
    void findTopSimilarBooks() {
        cout<<"Finding top 10 similar books..."<<endl;
@@ -271,7 +308,7 @@ class BookComparison
        int numPairs = min(10, static_cast<int>(similarityPairs.size()));

        // Open file for writing
        ofstream outFile("similar_Books.txt");
        ofstream outFile("outputFiles/similar_Books.txt");
        if (!outFile.is_open()) {
            cout << "Error opening file for writing" << endl;
            return;
@@ -290,7 +327,7 @@ class BookComparison

        outFile.close();
        cout<<"Most similar books have been found!"<<endl;
        cout << "\nResults have been written to similar_Books.txt" << endl;
        cout << "\nResults have been written to outputFiles/similar_Books.txt" << endl;
    }

};
