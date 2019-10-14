#pragma once

#include <array>
#include <rag/typeUtils.hpp>
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

    // TODO: One or more rank lists (DCL50-CPP)
    /**
     * @brief Conduct rank aggregation on two rank lists.
     *
     * @tparam Container type.
     * @tparam 0
     * @param A
     * @param B
     * @return Container
     */
    template <
        typename Container,
        std::enable_if<typeUtils::is_container<Container>::value, int> = 0>
    Container raggregate(Container const & A, Container const & B);

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
