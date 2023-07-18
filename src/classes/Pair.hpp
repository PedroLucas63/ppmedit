/**
 * @file Pair.hpp
 * @author Pedro Lucas (pedrolucas.jsrn@gmail.com)
 * @brief Pair setting.
 * @version 2.0
 * @date 2023-07-18
 * 
 * Defines a class that creates a pair between two data types. It is used
 * to define a value and give a description for it.
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef PAIR_HPP
#define PAIR_HPP

/**
 * @class Pair class.
 * @brief Pair definition with attributes and methods.
 * 
 * @details The template is used to allow the class description and value
 * to take on any data type.
 * 
 * @tparam Description Description of the pair.
 * @tparam Value Value of the pair.
 */
template <typename Description, typename Value>
class Pair {
public:
   /**
    * @brief Construct a new Pair object with no data.
    */
   Pair() { }

   /**
    * @brief Construct a new Pair object with data.
    * 
    * @param desc Description of the pair.
    * @param val Value of the pair.
    */
   Pair(Description desc, Value val) : description(desc), value(val) { }
   
   /**
    * @brief Construct a new Pair object with another pair (copy).
    *
    * @param rhs A pair to copy.
    * @see setDescription()
    * @see setValue()
    */
   Pair(Pair const& rhs) {
      setDescription(rhs.getDescription());
      setValue(rhs.getValue());
   }

   /**
    * @brief Destroy the pair object.
    */
   ~Pair() { }

   /**
    * @brief Operator to receive a pair (copy).
    *
    * @param rhs A pair to receive.
    * @see setDescription()
    * @see setValue()
    */
   void operator=(Pair const& rhs) {
      setDescription(rhs.getDescription());
      setValue(rhs.getValue());
   }

   /**
    * @brief Set the description in the pair.
    * 
    * @param desc Description.
    */
   void setDescription(Description desc) {
      description = desc;
   }

   /**
    * @brief Get the description of the pair.
    * 
    * @return An Description value.
    */
   Description getDescription() const {
      return description;
   }
   
   /**
    * @brief Set the value in the pair.
    * 
    * @param val Value.
    */
   void setValue(Value val) {
      value = val;
   }

   /**
    * @brief Get the value of the pair.
    * 
    * @return An Value value.
    */
   Value getValue() const {
      return value;
   }

private:
   Description description; /**< Description of the pair */
   Value value;             /**< Value of the pair */
};

#endif // PAIR_HPP
