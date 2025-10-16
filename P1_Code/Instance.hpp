#pragma once

#include <vector>
#include <string>

using namespace std;

/**
 *
 * Represents an instance of the knapsack problem.
 *
 *
 **/
class Instance {

    private:
        /// Array of item values c
        vector<int> values;

        /// Array of item weights w
        vector<int> weights;

        /// Knapsack weight limit W
        int weightLimit;

        /// Filename of the instance file
        string filename;

    public:


        /**
        * Constructs an instance for given item number.
        *
        * @param number of items in the instance
        */
        explicit Instance(int number);

        /**
        * Destructor for the instance.
        */
        ~Instance() = default;


        /**
         * Set value for an item.
         *
         * @param item Item index
         * @param value Value of item to be set
         */
        void setValue(int item, int value);
    
        /**
         * Get value for an item.
         *
         * @param item Item index
         *
         * @return The value of the item
         */
         int getValue(int item) const;
    
        /**
         * Set weight for an item.
         *
         * @param item Item index
         * @param weight Weight of item to be set
         */
         void setWeight(int item, int weight);
    
        /**
         * Get weight for an item.
         *
         * @param item Item index
         *
         * @return The weight of the item
         */
        int getWeight(int item) const;
    
        /**
         * Set the name of the instance.
         *
         * @param name New Name for the instance
         */
        void setFilename(string name);
    
        /**
         * Get the name of the instance.
         *
         * @return The filename of the instance
         */
        string getFilename() const;
    
        /**
         * Get weight limit (capacity of knapsack).
         *
         * @return The weight limit
         */
        int getCapacity() const;
    
        /**
         * Set weight limit (capacity of knapsack).
         *
         * @param capacity The capacity
         */
        void setCapacity(int capacity);

        
        /**
         * Set value and weight for an item.
         *
         * @param item Item index
         * @param value Value of item to be set
         * @param weight Weight of item to be set
         */
        void set(int item, int value, int weight);
    
        /**
        *
        * Get the number of items.
        *
        * @return the number of items of this instance.
        *
        **/
        int getNumberOfItems() const;

        /**
        *
        * Get the number of items.
        *
        * @return the number of items of this instance.
        *
        **/
        int n();

};