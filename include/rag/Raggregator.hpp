#pragma once

#include <array>
#include <string>

namespace rag
{
/**
 * @brief Class for handling rank aggregation.
 *
 * @tparam CType
 */
class Raggregator
{
public:
    /* Constructors */

    /**
     * @brief Construct a new Raggregator object.
     *
     */
    Raggregator();

    /**
     * @brief Construct a new Raggregator object using the given method.
     *
     * @param method
     */
    Raggregator(std::string const & method);

    /* Public class methods */

    // TODO: One or more rank lists
    /**
     * @brief Conduct rank aggregation on two rank lists.
     *
     * @param rankLists
     * @return CType
     */
    template <class CType>
    CType raggregate(CType const & A, CType const & B);

    /* Getters & setters */

    /**
     * @brief Get an array of the available rank aggregation methods.
     *
     * @return std::array<std::string, 4>
     */
    std::array<std::string, 4> getMethodOptions() const;

    /**
     * @brief Get the name of the currently selected rank aggregation method.
     *
     * @return std::string
     */
    std::string getMethodName() const;

    /**
     * @brief Set the rank aggregation method by its name.
     *
     * @param methodName
     * @return std::string
     */
    std::string setMethod(std::string const & methodName);

private:
    /* Private class variables */

    // The name of the currently selected method.
    std::string methodName;

    /* Private static class variables */

    // Names of the available rank aggregation methods.
    inline std::array<std::string, 4> static const METHOD_NAMES = {
        "heuristic", "borda", "condorcet", "kemeny"};
};

}  // namespace rag
