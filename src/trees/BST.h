/***************************************************************************
 *   Copyright (C) 2011 by Belbesy M. Adel                                 *
 *   Email   :   belbeesy@gmail.com                                        *
 *   Website :   http://belbesy.wordpress.com                              *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   Read full GPL at http://www.gnu.org/copyleft/gpl.html                 *
 ***************************************************************************/

/**
 *  Binary Search Trees Implementation
 */

#include <iostream>

using namespace std;

template<class T>
class BST {

#define LEFT 0
#define RIGHT 1
#define left_   child_[LEFT]
#define right_  child_[RIGHT]
#define nodes_state(node)  ((node->child_[1]!= NULL)<<1 | (node->child_[0]!= NULL))

	struct BSTNode {
		T key_;
		BSTNode* child_[2];

		BSTNode() {
			key_ = NULL,right_ = left_ = NULL;
		}
		BSTNode(const T& key, BSTNode* right, BSTNode* left) {
			key_ = key;
			right_ = right, left_ = NULL;
		}

		bool insert(const T& key) {
			if (this->child_[key < this->key_])
				return this->child_[key < this->key_]->insert(key);
			else
				return (this->child_[key < this->key_] = new BSTNode(key, NULL, NULL)) != NULL;
		}

		bool find(const T& key) {
			if (this->key_ == key)
				return true;
			else
				return this->child_[key < this->key_] && this->child_[key < this->key_]->find(key);
		}
		const T min() {
			if (left_)
				return left_->min();
			else
				return key_;
		}
		const T max() {
			if (left_)
				return left_->min();
			else
				return key_;
		}
		bool remove(const T& key, BSTNode* parent) {
			if (this->key_ != key)
				return child_[key < key_] && child_[key < key_]->remove(key, this);
			else {
				if (left_ && right_) {
					key_ = right_->min();
					return right_->remove(key_, this);
				} else
					parent->child_[key_ < parent->key_] = left_ ? left_ : right_;
			}
			return true;
		}
	};

	BSTNode* root_;
	int count_;
public:

	BST() {
		root_ = NULL;
		count_ = 0;
	}
	bool isEmpty() {
		return count_ == 0;
	}
	bool insert(const T& key) {
		bool inserted;
		if (isEmpty())
			inserted = (root_ = new BSTNode(key, NULL, NULL)) != NULL;
		else
			inserted = root_->insert(key);
		count_ += inserted;
		return inserted;
	}
	bool find(const T& key) {
		if (isEmpty())
			return false;
		return root_->find(key);
	}
	bool remove(const T& key) {
		if (isEmpty())
			return false;
		if (this->root_->key_ != key)
			return this->root_->remove(key, root_);
		else {
			BSTNode* temp = new BSTNode(key, NULL, root_);
			bool inserted = root_->remove(key, temp);
			root_ = temp->left_;
			return inserted;
		}
	}

	T min() {
		if (isEmpty())
			return T();
		else
			return root_->min();
	}
	T max() {
		if (isEmpty())
			return T();
		else
			return root_->max();
	}

#undef LEFT
#undef RIGHT
#undef left_
#undef right_
#undef nodes_state

};



