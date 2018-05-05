<?php

/**
 * @file
 * Retrieve legal info from nid.
 */

/**
 * Return data legal from sinister.
 */
function sinister_ws_legal_resource_retrieve($nid) {
  $legal = array();

  // This nid has the legal information.
  $nid = 1921;

  if (($node = node_load($nid))) {

    if (!empty($node->nid)) {
      $legal['id'] = $node->nid;
    }
    else {
      $legal['id'] = NULL;
    }

    if (!empty($node->created)) {
      $legal['created'] = date('Y/m/d H:s A', $node->created);
    }
    else {
      $legal['created'] = NULL;
    }

    if (!empty($node->title)) {
      $legal['title'] = $node->title;
    }
    else {
      $legal['title'] = NULL;
    }

    if (!empty($node->body[LANGUAGE_NONE][0]['value'])) {
      $legal['text'] = $node->body[LANGUAGE_NONE][0]['value'];
    }
    else {
      $legal['text'] = NULL;
    }
  }

  return $legal;
}
