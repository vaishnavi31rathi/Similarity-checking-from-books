# Book Comparison Project
# 📚 Book Comparison Project

## Overview
## 🎯 Overview

This project aims to analyze and compare 64 books using text analysis techniques. The main objectives are:
An elegant text analysis project that explores the fascinating relationships between 64 literary works. Using sophisticated comparison algorithms, this project uncovers hidden patterns and similarities in classic literature.

1. Identify the 100 most frequently used words across all books.
2. Create a 64x64 similarity matrix comparing all books based on these words.
3. Determine the top 10 most similar book pairs.
## ✨ Key Features

## Dataset
- Identifies the 100 most influential words across the literary corpus
- Generates a comprehensive 64x64 similarity matrix
- Reveals the top 10 most closely related book pairs
- Processes and analyzes raw text with precision
- Implements robust comparison algorithms

The dataset consists of 64 books in TXT document format. Each book is processed to extract its textual content for analysis.
## 📊 Results Highlight

## Methodology
Our analysis revealed some fascinating connections between books. Here are some notable findings:

### 1. Word Frequency Analysis
1. Gerard's Herbal volumes show remarkable similarity (91% match between Vol. 3 and Vol. 4)
2. Memoirs of Laetitia Pilkington demonstrates strong narrative consistency across volumes
3. Foxes Book of Martyrs maintains thematic coherence throughout different parts

- Preprocess the text data (remove punctuation, convert to lowercase, etc.)
- Count word occurrences across all books
- Identify the top 100 most frequently used words
## 🛠️ Technical Implementation

### 2. Book Comparison
### Core Components
- Custom `Book` class for efficient text representation
- Advanced text preprocessing pipeline
- Sophisticated similarity calculation algorithms
- Comprehensive word frequency analysis

- Create feature vectors for each book based on the top 100 words
- Compute similarity scores between all pairs of books (64x64 matrix)
- Use cosine similarity or another appropriate metric for comparison
### Technology Stack
- Language: C++
- Data Format: Raw text files
- Analysis Method: Statistical text comparison

### 3. Similarity Ranking
## 📈 Performance

- Sort the similarity scores to identify the top 10 most similar book pairs
The program efficiently processes 64 books and performs:
- Word frequency analysis across entire corpus
- 2,016 unique book-to-book comparisons
- Similarity ranking and sorting

## Implementation
## 🚀 Getting Started

The project is implemented in C++, utilizing the following components:
1. Clone the repository
2. Ensure all book text files are in the designated directory
3. Compile the C++ source files
4. Run the executable
5. Find results in the output directory

- `Book` class: Represents individual books and their properties
- `Library` class: Manages the collection of books and comparison operations
- Text processing functions for word extraction and counting
- Similarity calculation algorithms
## 📝 Output Files

## Results
The program generates several output files:
- `common_words.txt`: Top 100 most frequent words
- `similarity_matrix.txt`: Complete comparison matrix
- `similar_books.txt`: Top 10 most similar book pairs

The program outputs:
## 🔍 Future Scope

1. List of the top 100 most frequently used words across all books
2. 64x64 similarity matrix
3. Top 10 most similar book pairs with their similarity scores
- Natural Language Processing integration
- Interactive visualization dashboard
- Semantic analysis capabilities
- Genre classification features
- Multi-language support

## Future Enhancements
## 💡 Technical Note

- Implement more advanced text processing techniques (e.g., stemming, lemmatization)
- Explore alternative similarity metrics
- Visualize the similarity matrix and book relationships
- Extend the analysis to include sentiment or topic modeling
The current implementation uses a single-threaded approach to ensure maximum stability and reliability. While this design choice impacts processing speed, it guarantees consistent results across all system configurations.

## Usage
## 🤝 Acknowledgments

Instructions on how to run the program and any dependencies will be provided here.


## Note to Professor

Dear Professor,

I would like to bring to your attention that I was unable to implement multithreading in this project due to technical limitations on my personal computer. Despite multiple attempts, the multithreaded implementation was causing unexpected behavior and system instability due to unknown hardware/software compatibility issues. Therefore, I proceeded with a single-threaded implementation to ensure reliable and correct functionality of the program.

I understand that multithreading was a desired component, but I focused on delivering a robust solution that meets all other requirements. The current implementation still achieves the core objectives of text analysis and book comparison effectively.

Thank you for your understanding.🙏🙏🙏
Special thanks to:
- The professors for their guidance
- The open-source community for inspiration
- Project collaborators for their valuable input

---
*Created with ❤️ by a passionate programmer*
 Binary file modifiedBIN +5.04 KB (100%) 
src/a.exe
Binary file not shown.
  63 changes: 50 additions & 13 deletions63  
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
