#ifndef BDD_H
#define BDD_H

#include <memory>
#include <iostream>


using Variable = unsigned;

class BDDNode;
using BDD = std::shared_ptr<BDDNode>;


class BDDNode : public std::enable_shared_from_this<BDDNode>
{
public:
    BDDNode(Variable v, bool highValue = true, bool lowValue = false);

    void insert(Variable v, bool highValue = true, bool lowValue = false);
    std::ostream& print(std::ostream& out) const;

private:

    void insertInternal(Variable v, bool highValue, bool lowValue, unsigned level);

    bool m_value;
    BDD m_low;
    BDD m_high;
    Variable m_var;
};

std::ostream& operator<<(std::ostream& out, const BDD &bdd);

#endif // BDD_H
